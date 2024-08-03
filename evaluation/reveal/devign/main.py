import argparse
import json
import os
import pickle
import sys
import tqdm
import random

import numpy as np
import torch
from torch.nn import BCELoss
from torch.optim import Adam

from data_loader.dataset import DataSet
from modules.model import DevignModel, GGNNSum
from trainer import train, evaluate_metrics, get_embeddings
from utils import tally_param, debug

if __name__ == '__main__':

    import dgl
    import warnings

    warnings.filterwarnings('ignore')

    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', type=str, help='Mode of the script (train/test)', default='train')
    parser.add_argument('--train_mode', type=str,
                        help='Mode of the train (step_2000/patience_20/step_2000_valid/patience_20_valid)',
                        default='step_2000')
    parser.add_argument('--dataset_root', type=str, help='Root directory of the dataset.',
                        default='./data_storage')
    parser.add_argument('--dataset', type=str, help='Name of the dataset for experiment.',
                        default='devign_non_non_reveal')
    parser.add_argument('--train_src', nargs='*', help='Path to the training source file.',
                        default=['./data/origin_output/devign.shard1',
                                 './data/origin_output/devign.shard2',
                                 './data/origin_output/devign.shard3',
                                 './data/origin_output/devign.shard4',
                                 './data/origin_output/devign.shard5'])
    parser.add_argument('--part_src', nargs='*', help='Path to the part source file.',
                        default=None)
    parser.add_argument('--test1_src', nargs='*', help='Path to the testing source file.',
                        default=None)
    parser.add_argument('--test2_src', nargs='*', help='Path to the testing source file.',
                        default=None)
    # default=['./data/origin_output/reveal.shard1'])
    parser.add_argument('--test_model', type=str, help='use model to test.', default='devign_non_non_reveal')
    # parser.add_argument('--output_dir', type=str, help='Input Directory of the parser', default='./data_storage/devign_non_non_reveal')
    parser.add_argument('--seed', type=int, help='Seed for randomization', default=1000)
    parser.add_argument('--processed_train_path', type=str, help='Path to the processed train data.',
                        default='../../devign_storage/shard/reveal')
    parser.add_argument('--processed_part_path', type=str, help='Path to the processed part data.', default=None)
    parser.add_argument('--processed_test1_path', type=str, help='Path to the processed test data.',
                        default='../../devign_storage/shard/reveal')
    parser.add_argument('--processed_test2_path', type=str, help='Path to the processed test data.',
                        default='../../devign_storage/shard/reveal')

    parser.add_argument('--model_type', type=str, help='Type of the model (devign/ggnn)',
                        choices=['devign', 'ggnn'], default='devign')
    parser.add_argument('--node_tag', type=str, help='Name of the node feature.', default='node_features')
    parser.add_argument('--graph_tag', type=str, help='Name of the graph feature.', default='graph')
    parser.add_argument('--label_tag', type=str, help='Name of the label feature.', default='targets')

    parser.add_argument('--feature_size', type=int, help='Size of feature vector for each node', default=169)
    parser.add_argument('--graph_embed_size', type=int, help='Size of the Graph Embedding', default=200)
    parser.add_argument('--num_steps', type=int, help='Number of steps in GGNN', default=6)
    parser.add_argument('--batch_size', type=int, help='Batch Size for training', default=128)
    args = parser.parse_args()

    # seed
    random.seed(args.seed)
    np.random.seed(args.seed)
    torch.manual_seed(args.seed)
    torch.cuda.manual_seed_all(args.seed)
    dgl.seed(args.seed)
    os.environ['PYTHONHASHSEED'] = str(args.seed)
    os.environ['CUBLAS_WORKSPACE_CONFIG'] = ':4096:8'
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False
    torch.use_deterministic_algorithms(True)

    if args.mode == 'test':
        is_test = True
    else:
        is_test = False
    output_dir = os.path.join(args.dataset_root, args.dataset)

    if args.feature_size > args.graph_embed_size:
        print('Warning!!! Graph Embed dimension should be at least equal to the feature dimension.\n'
              'Setting graph embedding size to feature size', file=sys.stderr)
        args.graph_embed_size = args.feature_size

    model_dir = os.path.join(output_dir, 'models-seed' + str(args.seed))
    if not os.path.exists(model_dir):
        os.makedirs(model_dir)
    # processed_data_path = os.path.join(output_dir, 'processed.bin')
    # processed_train_path = os.path.join(args.processed_train_path, 'processed.bin')
    # processed_test_path = os.path.join(args.processed_test_path, 'processed.bin')
    #
    # test_model_dir = os.path.join(args.dataset_root, args.test_model)
    # test_model_dir = os.path.join(test_model_dir, 'models-seed' + str(args.seed))
    #
    # if os.path.exists(processed_train_path):
    #     debug('Reading already processed data from %s!' % processed_train_path)
    #     dataset = pickle.load(open(processed_train_path, 'rb'))
    #     debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples))
    # else:
    #     dataset = DataSet(train_src=args.train_src,
    #                       valid_src=None,
    #                       test_src=None,
    #                       batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
    #                       l_ident=args.label_tag)
    #     file = open(processed_train_path, 'wb')
    #     pickle.dump(dataset, file)
    #     file.close()
    #
    # if args.processed_part_path is not None:
    #     processed_part_path = os.path.join(args.processed_part_path, 'processed.bin')
    #     if os.path.exists(processed_part_path):
    #         debug('Reading already processed data from %s!' % processed_part_path)
    #         part = pickle.load(open(processed_part_path, 'rb'))
    #         debug(len(part.train_examples), len(part.valid_examples), len(part.test_examples))
    #     else:
    #         part = DataSet(train_src=args.part_src,
    #                        valid_src=[],
    #                        test_src=[],
    #                        batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
    #                        l_ident=args.label_tag)
    #         file = open(processed_part_path, 'wb')
    #         pickle.dump(part, file)
    #         file.close()
    #         debug(len(part.train_examples), len(part.valid_examples), len(part.test_examples))
    #     dataset.train_examples += part.train_examples
    #     debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples))
    #
    # if os.path.exists(processed_test_path):
    #     debug('Reading already processed data from %s!' % processed_test_path)
    #     dataset_test = pickle.load(open(processed_test_path, 'rb'))
    #     debug(len(dataset_test.train_examples), len(dataset_test.valid_examples), len(dataset_test.test_examples)
    #     )
    # else:
    #     dataset_test = DataSet(train_src=None,
    #                       valid_src=None,
    #                       test_src=args.test_src,
    #                       batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
    #                       l_ident=args.label_tag)
    #     file = open(processed_test_path, 'wb')
    #     pickle.dump(dataset_test, file)
    #     file.close()
    # dataset.test_examples = dataset_test.test_examples
    # debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples))

    # if os.path.exists(processed_data_path):
    #     debug('Reading already processed data from %s!' % processed_data_path)
    #     dataset = pickle.load(open(processed_data_path, 'rb'))
    #     debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples))
    # else:
    #     dataset = DataSet(train_src=args.train_src,
    #                       valid_src=None,
    #                       test_src=args.test_src,
    #                       batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
    #                       l_ident=args.label_tag)
    #     file = open(processed_data_path, 'wb')
    #     pickle.dump(dataset, file)
    #     file.close()
    test_model_dir = model_dir

    if not is_test:
        processed_train_path = os.path.join(args.processed_train_path, 'processed.bin')

        if os.path.exists(processed_train_path):
            debug('Reading already processed train data from %s!' % processed_train_path)
            train_dataset = pickle.load(open(processed_train_path, 'rb'))
            dataset = DataSet(train_src=['/root/my_eval/RQ1/devign_storage/shard/test1/test.shard'],
                              valid_src=[],
                              test_src=[],
                              test1_src=[],
                              test2_src=[],
                              batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                              l_ident=args.label_tag)
            dataset.train_examples = train_dataset.train_examples
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))
        else:
            dataset = DataSet(train_src=args.train_src,
                              valid_src=[],
                              test_src=[],
                              test1_src=[],
                              test2_src=[],
                              batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                              l_ident=args.label_tag)
            file = open(processed_train_path, 'wb')
            pickle.dump(dataset, file)
            file.close()
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))

        if args.processed_part_path is not None:
            processed_part_path = os.path.join(args.processed_part_path, 'processed.bin')
            if os.path.exists(processed_part_path):
                debug('Reading already processed part data from %s!' % processed_part_path)
                part_dataset = pickle.load(open(processed_part_path, 'rb'))
                part = DataSet(train_src=[],
                               valid_src=[],
                               test_src=[],
                               test1_src=[],
                               test2_src=[],
                               batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                               l_ident=args.label_tag)
                part.train_examples = part_dataset.train_examples
            else:
                part = DataSet(train_src=args.part_src,
                               valid_src=[],
                               test_src=[],
                               test1_src=[],
                               test2_src=[],
                               batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                               l_ident=args.label_tag)
                file = open(processed_part_path, 'wb')
                pickle.dump(part, file)
                file.close()
            debug(len(part.train_examples), len(part.valid_examples), len(part.test_examples),
                  len(part.test1_examples), len(part.test2_examples))
            dataset.train_examples += part.train_examples
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))

        processed_test1_path = os.path.join(args.processed_test1_path, 'processed.bin')
        if os.path.exists(processed_test1_path):
            debug('Reading already processed test1 data from %s!' % processed_test1_path)
            test1_dataset = pickle.load(open(processed_test1_path, 'rb'))
            test1 = DataSet(train_src=[],
                            valid_src=[],
                            test_src=[],
                            test1_src=[],
                            test2_src=[],
                            batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                            l_ident=args.label_tag)
            test1.test_examples = test1_dataset.test_examples
        else:
            test1 = DataSet(train_src=[],
                            valid_src=[],
                            test_src=args.test1_src,
                            test1_src=[],
                            test2_src=[],
                            batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                            l_ident=args.label_tag)
            file = open(processed_test1_path, 'wb')
            pickle.dump(test1, file)
            file.close()
        debug(len(test1.train_examples), len(test1.valid_examples), len(test1.test_examples),
              len(test1.test1_examples), len(test1.test2_examples))
        dataset.test1_examples = test1.test_examples
        debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
              len(dataset.test1_examples), len(dataset.test2_examples))

        if args.processed_test2_path is not None:
            processed_test2_path = os.path.join(args.processed_test2_path, 'processed.bin')
            if os.path.exists(processed_test2_path):
                debug('Reading already processed test2 data from %s!' % processed_test2_path)
                test2_dataset = pickle.load(open(processed_test2_path, 'rb'))
                test2 = DataSet(train_src=[],
                                valid_src=[],
                                test_src=[],
                                test1_src=[],
                                test2_src=[],
                                batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                                l_ident=args.label_tag)
                test2.test_examples = test2_dataset.test_examples
            else:
                test2 = DataSet(train_src=[],
                                valid_src=[],
                                test_src=args.test2_src,
                                test1_src=[],
                                test2_src=[],
                                batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                                l_ident=args.label_tag)
                file = open(processed_test2_path, 'wb')
                pickle.dump(test2, file)
                file.close()
            debug(len(test2.train_examples), len(test2.valid_examples), len(test2.test_examples),
                  len(test2.test1_examples), len(test2.test2_examples))
            dataset.test2_examples = test2.test_examples
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))

    else:
        processed_test1_path = os.path.join(args.processed_test1_path, 'processed.bin')
        if os.path.exists(processed_test1_path):
            debug('Reading already processed test1 data from %s!' % processed_test1_path)
            dataset = pickle.load(open(processed_test1_path, 'rb'))
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))
        else:
            dataset = DataSet(train_src=[],
                              valid_src=[],
                              test_src=args.test1_src,
                              test1_src=[],
                              test2_src=[],
                              batch_size=args.batch_size, n_ident=args.node_tag, g_ident=args.graph_tag,
                              l_ident=args.label_tag)
            file = open(processed_test1_path, 'wb')
            pickle.dump(dataset, file)
            file.close()
            debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
                  len(dataset.test1_examples), len(dataset.test2_examples))

        dataset.test1_examples = dataset.test_examples
        debug(len(dataset.train_examples), len(dataset.valid_examples), len(dataset.test_examples),
              len(dataset.test1_examples), len(dataset.test2_examples))

    assert args.feature_size == dataset.feature_size, \
        'Dataset contains different feature vector than argument feature size. ' \
        'Either change the feature vector size in argument, or provide different dataset.'
    vulsamples = 0
    for train_example in dataset.train_examples:
        if train_example.target == 1:
            vulsamples += 1
    print("train:", len(dataset.train_examples), vulsamples)
    vulsamples = 0
    for test_example in dataset.test_examples:
        if test_example.target == 1:
            vulsamples += 1
    print("test:", len(dataset.test_examples), vulsamples)
    vulsamples = 0
    for test1_example in dataset.test1_examples:
        if test1_example.target == 1:
            vulsamples += 1
    print("test1:", len(dataset.test1_examples), vulsamples)
    vulsamples = 0
    for test2_example in dataset.test2_examples:
        if test2_example.target == 1:
            vulsamples += 1
    print("test2:", len(dataset.test2_examples), vulsamples)
    # assert 0

    if args.model_type == 'ggnn':
        model = GGNNSum(input_dim=dataset.feature_size, output_dim=args.graph_embed_size,
                        num_steps=args.num_steps, max_edge_types=dataset.max_edge_type)
    else:  # devign
        model = DevignModel(input_dim=dataset.feature_size, output_dim=args.graph_embed_size,
                            num_steps=args.num_steps, max_edge_types=dataset.max_edge_type)

    debug('Total Parameters : %d' % tally_param(model))
    debug('#' * 100)
    model.cuda()
    loss_function = BCELoss(reduction='sum')
    optim = Adam(model.parameters(), lr=0.0001, weight_decay=0.001)

    if is_test:
        # model = torch.load("./data_storage/devign_vulgen/models/GGNNSumModel-model.bin1919")
        model_path = os.path.join(test_model_dir, 'GGNNSumModel-model.bin')
        model = torch.load(model_path)
        model.train()
    else:
        model.train()
        model = train(model=model, dataset=dataset, max_steps=0, dev_every=200,
                      loss_function=loss_function, optimizer=optim,
                      save_path=model_dir + '/GGNNSumModel', max_patience=20, log_every=None,
                      train_mode=args.train_mode)
    # neg_metrics = []
    # avg_metrics = []
    # other_metrics = []
    # acc, prec, rec, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
    #                                       dataset.get_next_test_batch, neg_metrics, avg_metrics, other_metrics)

    get_embeddings(model, loss_function, dataset.initialize_train_batch(),
                   dataset.get_next_train_batch, model_dir + "/reveal_train_after_ggnn.json")
    get_embeddings(model, loss_function, dataset.initialize_test1_batch(),
                   dataset.get_next_test1_batch, model_dir + "/reveal_test1_after_ggnn.json")
    get_embeddings(model, loss_function, dataset.initialize_test2_batch(),
                   dataset.get_next_test2_batch, model_dir + "/reveal_test2_after_ggnn.json")

    # print("pos testing result:", acc, prec, rec, f1)
    # print("neg testing result:", neg_metrics)
    # print("avg testing result:", avg_metrics)
    # print("auc: ", other_metrics[0], "mcc: ", other_metrics[1], "pos_g_m: ", other_metrics[2], "neg_g_m: ", other_metrics[3], "avg_g_m: ", other_metrics[4])
