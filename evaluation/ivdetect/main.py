
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
                        default='output_sam_data/')
    # parser.add_argument('--data_split', type=str, help='data split id',
    #                     default='0')
    parser.add_argument("--train_shards", nargs="*", type=int, default=[0, 1, 2, 3, 4])
    parser.add_argument("--test_shards", nargs="*", type=int, default=[5])
    parser.add_argument('-d', '--device', type=str, default='cuda:0')
    parser.add_argument('--seed', type=int, default=12345)
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
    max_epochs = params['epochs']
    device = args.device
    backbone_model = vul_model.Vulnerability_backbone(h_size=params['hidden_size'], num_node_feature=5, num_classes=2,
                                                      feature_representation_size=params['hidden_size'],
                                                      drop_out_rate=params['dropout_rate'],
                                                      num_conv_layers=params['num_conv_layers'])

    pretrain_model = vul_model.backbone_mlp(backbone_model, params['hidden_size'])

    pytorch_total_params = sum(p.numel() for p in pretrain_model.parameters())
    print('total parameter:', pytorch_total_params)
    # pretrain_optimizer = torch.optim.Adam(pretrain_model.parameters(), lr=params['lr'])
    learning_rate = params['lr']
    rho = 0
    pretrain_optimizer = SAM(pretrain_model.parameters(), torch.optim.Adam, lr=learning_rate)
    
    #     exit()
    # weights = torch.tensor([1.0, 19316 / 9316]).to(device)
    weights = torch.tensor([1.0, 1.0]).to(device)
    print(f'weights: {weights}')
    criterion = nn.CrossEntropyLoss(weight=weights)
    if device != 'cpu':
        pretrain_model.to(device)
    for epoch in range(1, max_epochs):
        print(f'pretrain epochs {epoch}')
        logging.info(f'pretrain epochs {epoch}')
        pretrain_model.train()
        train_code = []
        train_X = []
        train_y = []
        count = 0
        for index, graph in enumerate(tqdm(train_loader, desc='train')):
            # print(graph)
            # exit()
            if device != 'cpu':
                graph = graph.to(device)
            target = graph.y
            pretrain_optimizer.zero_grad()
            if len(graph.my_data[0].data.shape) == 1:
                count += 1
                continue

            out = pretrain_model(graph.my_data, graph.edge_index)
            loss = criterion(out, target)
            loss.backward()
            # pretrain_optimizer.step()
            pretrain_optimizer.first_step(zero_grad=True)
            out = pretrain_model(graph.my_data, graph.edge_index)
            loss = criterion(out, target)
            loss.backward()
            pretrain_optimizer.second_step(zero_grad=True)
            
            train_X.append(out.cpu().detach().numpy())
            train_y.append(target.cpu().detach().numpy())
        print(f'pretrain epochs {epoch} finish')
        logging.info(f'pretrain epochs {epoch} finish')
        print(f'count: {count}')
        torch.save(pretrain_model.state_dict(), f'{args.out_dir}_pretrain_ep_{epoch}.dt')
        train_y_np = np.array(train_y)
        train_X_np = np.array(train_X)
        train_X_np = np.squeeze(train_X_np, axis=1)
        torch.save(train_code, f'{args.out_dir}_trainCode_ep_{epoch}.dt')
        torch.save(train_X_np, f'{args.out_dir}_trainX_ep_{epoch}.dt')
        torch.save(train_y_np, f'{args.out_dir}_trainy_ep_{epoch}.dt')
        with torch.no_grad():
            pretrain_model.eval()
            # train_code = []
            # train_X = []
            # train_y = []
            # for index, graph in enumerate(tqdm(train_loader),desc="train"):
            #     train_code.append(graph.code)
            #     if device != 'cpu':
            #         graph = graph.to(device)
            #     target = graph.y
            #     out = pretrain_model.backbone(graph.my_data, graph.edge_index)
            #     # print(out.shape)
            #     train_X.append(out.cpu().detach().numpy())
            #     train_y.append(target.cpu().detach().numpy())
            # train_y_np = np.array(train_y)
            # train_X_np = np.array(train_X)
            # train_X_np = np.squeeze(train_X_np,axis = 1)
            # torch.save(train_code,f'{args.out_dir}_trainCode_ep_{epoch}.dt')
            # torch.save(train_X_np,f'{args.out_dir}_trainX_ep_{epoch}.dt')
            # torch.save(train_y_np,f'{args.out_dir}_trainy_ep_{epoch}.dt')
            test_code = []
            # test_cve = []
            # test_cwe = []
            test_X = []
            test_y = []
            all_predictions, all_targets, all_probs = [], [], []
            for index, graph in enumerate(tqdm(test_loader, desc='test')):
                test_code.append(graph.code)
                # test_cve.append(graph.cve_type)
                # test_cwe.append(graph.cwe_type)
                if device != 'cpu':
                    graph = graph.to(device)
                target = graph.y
                latent_out = pretrain_model.backbone(graph.my_data, graph.edge_index)
                out = pretrain_model(graph.my_data, graph.edge_index)
                pred = out.argmax(dim=1).cpu().detach().numpy()
                prob_1 = out.cpu().detach().numpy()[0][1]
                # print(out.shape)
                test_X.append(latent_out.cpu().detach().numpy())
                test_y.append(target.cpu().detach().numpy())
                all_probs.append(prob_1)
                all_predictions.append(pred)
                all_targets.append(target.cpu().detach().numpy())
            test_y = np.array(test_y)
            test_X = np.array(test_X)
            test_X = np.squeeze(test_X, axis=1)
            torch.save(test_code, f'{args.out_dir}_testCode_ep_{epoch}.dt')
            torch.save(test_X, f'{args.out_dir}_testX_ep_{epoch}.dt')
            torch.save(test_y, f'{args.out_dir}_testy_ep_{epoch}.dt')
            torch.save(all_predictions, f'{args.out_dir}_testPreds_ep_{epoch}.dt')
            torch.save(all_targets, f'{args.out_dir}_testTargets_ep_{epoch}.dt')
            torch.save(all_probs, f'{args.out_dir}_testProbs_ep_{epoch}.dt')
            # torch.save(# test_cve,f'{args.out_dir}_testCve_ep_{epoch}.dt')
            # torch.save(# test_cwe,f'{args.out_dir}_testCwe_ep_{epoch}.dt')
            # print(all_predictions)
            # print(all_targets)

    # with open(f'{args.out_dir}_testPreds_ep_{epoch}.dt', 'r') as f:
    #     test_preds = f.read()
    # with open(f'{args.out_dir}_testTargets_ep_{epoch}.dt', 'r') as f:
    #     test_targets = f.read()
    # with open(f'{args.out_dir}_testProbs_ep_{epoch}.dt', 'r') as f:
    #     test_probs = f.read()
    # result = my_metric(test_preds, test_targets, test_probs)
    # print(result)