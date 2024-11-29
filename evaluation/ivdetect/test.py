import os
import torch
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix, \
    classification_report, roc_curve, auc
from torch import nn
# from IVDetect_model import vul_model
import vul_model
from tqdm import tqdm
from torch.utils.data import DataLoader, Dataset
import argparse
import numpy as np
from imblearn.over_sampling import RandomOverSampler
from imblearn.under_sampling import RandomUnderSampler, OneSidedSelection
import logging
from torch.nn.utils.rnn import pad_packed_sequence
from operator import itemgetter
import random
from torch.nn.utils.rnn import pack_sequence
from collections import Counter
from sam import SAM
import GNNExplainer
import gnnexplainer
import json
import time
from torch_geometric.explain import Explainer, GNNExplainer

def extractDigits(lst):
    res = []
    for el in lst:
        sub = el.split(', ')
        res.append(sub)
    return (res)


class MyDatset(Dataset):
    def __init__(self, _datapoint_files, sampling=None):
        if sampling == None:
            self.datapoint_files = _datapoint_files
        elif sampling == 'ros':
            print("sample ros")

            # 收集目标标签
            list_of_targets = []
            for file in tqdm(_datapoint_files):
                graph = torch.load(file)
                list_of_targets.append(graph.y.numpy()[0])  # 取出标签

            # 打印重采样前的类别分布
            print(f'before sample 0:{Counter(list_of_targets)[0]}, 1:{Counter(list_of_targets)[1]}')

            # 提取文件列表
            train_files_list = extractDigits(_datapoint_files)

            # 分离正样本和负样本
            negative_samples = [train_files_list[i] for i in range(len(list_of_targets)) if list_of_targets[i] == 0]
            positive_samples = [train_files_list[i] for i in range(len(list_of_targets)) if list_of_targets[i] == 1]

            # 获取正样本的数量
            x = len(positive_samples)
            target_positive_count = 10000

            # 处理正样本不足10000个的情况
            if x < target_positive_count:
                # 计算需要额外采样的数量
                additional_samples_needed = target_positive_count
                # 重复正样本直到满足数量
                repeated_positive_samples = (positive_samples * ((additional_samples_needed // x) + 1))[
                                            :additional_samples_needed]
                # 将重复的正样本和负样本合并
                train_files_list_resampled = negative_samples + positive_samples + repeated_positive_samples
                list_of_targets_resampled = [0] * len(negative_samples) + [1] * len(positive_samples) + [1] * len(
                    repeated_positive_samples)
            else:
                # 如果正样本大于或等于10000个，则直接取前10000个正样本
                sampled_positive_samples = positive_samples[:target_positive_count]
                train_files_list_resampled = negative_samples + positive_samples + sampled_positive_samples
                list_of_targets_resampled = [0] * len(negative_samples) + [1] * len(positive_samples) + [
                    1] * target_positive_count

            # 打印重采样后的类别分布
            print(f'after sample 0:{Counter(list_of_targets_resampled)[0]}, 1:{Counter(list_of_targets_resampled)[1]}')

            # 展平文件列表
            flat_list = [item for sublist in train_files_list_resampled for item in sublist]
            self.datapoint_files = flat_list

    def __getitem__(self, index):
        graph_file = f'{self.datapoint_files[index]}'
        graph = torch.load(graph_file)
        # if len(graph.my_data[0].data.shape) != 1:
        #     import pdb
        #     pdb.set_trace()
        #     fea_2 = [torch.zeros(1, 100), graph.my_data[0].batch_sizes, graph.my_data[0].sorted_indices,
        #              graph.my_data[0].unsorted_indices]
        #     fea_2 = pack_sequence(fea_2, enforce_sorted=False)
        #     graph.my_data[0] = fea_2
        # print(graph.my_data[0].data.shape)
        return graph

    def __len__(self):
        return len(self.datapoint_files)


def my_metric(all_predictions, all_targets, all_probs):
    fpr, tpr, _ = roc_curve(all_targets, all_probs)
    auc_score = round(auc(fpr, tpr) * 100, 2)
    acc = round(accuracy_score(all_targets, all_predictions) * 100, 2)
    precision = round(precision_score(all_targets, all_predictions) * 100, 2)
    f1 = round(f1_score(all_targets, all_predictions) * 100, 2)
    recall = round(recall_score(all_targets, all_predictions) * 100, 2)
    matrix = confusion_matrix(all_targets, all_predictions)
    target_names = ['non-vul', 'vul']
    report = classification_report(all_targets, all_predictions, target_names=target_names)
    result = f'auc: {auc_score} acc: {acc} precision: {precision} recall: {recall} f1: {f1} \nreport:\n{report}\nmatrix:\n{matrix}'
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--processed_dir', type=str, help='dir of processed split datapoints',
                        default='input_data/')
    parser.add_argument('--sampling', type=str, help='sampling method',
                        default=None)
    parser.add_argument('--out_dir', type=str, help='output of trained model state',
                        # default='output_focalloss_data/')
                        # default='output_ros_data/')
                        default='output_data/')
    # parser.add_argument('--data_split', type=str, help='data split id',
    #                     default='0')
    parser.add_argument("--train_shards", nargs="*", type=int, default=[0, 1, 2, 3, 4])
    parser.add_argument("--test_shards", nargs="*", type=int, default=[10000])
    parser.add_argument('-d', '--device', type=str, default='cuda:0')
    parser.add_argument('--seed', type=int, default=12345)
    parser.add_argument('--load_model', type=str, default='0_storage_bigvul/output_data/')
    args = parser.parse_args()
    params = {'hidden_size': 100, 'lr': 1e-4, 'dropout_rate': 0.5, 'epochs': 3, 'num_conv_layers': 3}
    logging.basicConfig(filename=args.out_dir + f'/train_{args.train_shards}_test_{args.test_shards}.log',
                        level=logging.DEBUG)
    print(f'device use:', args.device)
    print(f'sampling : {args.sampling}')
    logging.info(f'sampling : {args.sampling}')
    print(f'curr dir: {os.getcwd()} ,reading processed datas from {args.processed_dir}')
    logging.info(f'curr dir: {os.getcwd()} ,reading processed datas from {args.processed_dir}')

    # seed
    random.seed(args.seed)
    np.random.seed(args.seed)
    torch.manual_seed(args.seed)
    torch.cuda.manual_seed_all(args.seed)
    # dgl.seed(args.seed)
    os.environ['PYTHONHASHSEED'] = str(args.seed)
    # os.environ['CUBLAS_WORKSPACE_CONFIG'] = ':4096:8'
    # torch.backends.cudnn.deterministic = True
    # torch.backends.cudnn.benchmark = False
    # torch.use_deterministic_algorithms(True)

    train_files = []
    test_files = []
    for i in args.train_shards:
        train_path = args.processed_dir + f'{i}/'
        train_files.extend([train_path + f for f in os.listdir(train_path) if
                            os.path.isfile(os.path.join(train_path, f))])
    train_dataset = MyDatset(train_files, sampling=args.sampling)
    for i in args.test_shards:
        test_path = args.processed_dir + f'{i}/'
        test_files.extend([test_path + f for f in os.listdir(test_path) if
                           os.path.isfile(os.path.join(test_path, f))])
    test_dataset = MyDatset(test_files)

    print(f'train {len(train_dataset)} test {len(test_dataset)}')
    # print(f'{args.out_dir}')
    logging.info(f'train {len(train_dataset)} test {len(test_dataset)}')
    train_loader = DataLoader(train_dataset, batch_size=None, batch_sampler=None,
                              shuffle=True)  # todo: shuffle set to False for testing
    test_loader = DataLoader(test_dataset, batch_size=None, batch_sampler=None, shuffle=False)

    device = args.device
    backbone_model = vul_model.Vulnerability_backbone(h_size=params['hidden_size'], num_node_feature=5, num_classes=2,
                                                      feature_representation_size=params['hidden_size'],
                                                      drop_out_rate=params['dropout_rate'],
                                                      num_conv_layers=params['num_conv_layers'])

    pretrain_model = vul_model.backbone_mlp(backbone_model, params['hidden_size'])

    load_path = args.load_model + '_pretrain_ep_1.dt'
    checkpoint = torch.load(load_path)
    pretrain_model.load_state_dict(checkpoint)

    pytorch_total_params = sum(p.numel() for p in pretrain_model.parameters())
    print('total parameter:', pytorch_total_params)

    if device != 'cpu':
        pretrain_model.to(device)
    # with torch.no_grad():
    pretrain_model.eval()

    # if os.path.exists(f'{args.load_model}0_result.json'):
    #     result = json.load(open(f'{args.load_model}0_result.json'))
    # else:
    result = []
    for index, graph in enumerate(tqdm(test_loader, desc='test')):
        # if graph.edge_index.max() < 5:
        #     continue
        try:
            if device != 'cpu':
                graph = graph.to(device)
            target = graph.y
            feat = pretrain_model.forward_first(graph.my_data, graph.edge_index).detach()
            graph.x = feat

            explainer = Explainer(
                model=pretrain_model,
                algorithm=gnnexplainer.GNNExplainer(),
                explanation_type='model',
                node_mask_type='attributes',
                edge_mask_type='object',
                model_config=dict(
                    mode='binary_classification',
                    task_level='graph',
                    return_type='probs',
                ),
            )
            explanation = explainer(graph.x, graph.edge_index)
            node_importance = explanation.node_mask.mean(dim=1)
            ret = sorted(
                list(
                    zip(
                        node_importance.detach().cpu().numpy(),
                        graph.stmt_keys,
                    )
                ),
                reverse=True,
            )
            # import pdb
            # pdb.set_trace()
            lines = [x[1] for x in ret]
            # lines = GNNExplainer.gnnexplainer(pretrain_model, graph)
            result.append({"pred": lines, "corr": [int(x) for x in graph.lines.split(', ')]})
        except Exception as e:
            print(f'error in {index}')


    json.dump(result, open(f'{args.load_model}0_result.json', 'w'), indent=4)

    correct_count = 0
    total_samples = 0
    for res in result:
        if sum(res['corr']) > 0:
            total_samples += 1
            top_k_pred = res['pred'][:10]
            if any(label in top_k_pred for label in res['corr']):
                correct_count += 1
    if total_samples > 0:
        top_k_acc = correct_count / total_samples
    else:
        top_k_acc = 0
    print(f'top_k_acc: {top_k_acc}')