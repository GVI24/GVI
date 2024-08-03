import argparse
import json
import numpy
import os
import sys
import torch
import pickle
import joblib
from representation_learning_api import RepresentationLearningModel
from sklearn.model_selection import train_test_split
from baseline_svm import SVMLearningAPI
import random

if __name__ == '__main__':

    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', type=str, help='Mode of the script (train/test)', default='train')
    # parser.add_argument('--train_mode', type=str, help='Mode of the train (step_2000/patience_20/step_2000_valid/patience_20_valid)', default='step_2000')
    parser.add_argument('--dataset_root', type=str, default='./data_storage')
    parser.add_argument('--dataset', type=str, help='Output dataset name.', default='reveal')
    # choices=['chrome_debian/balanced', 'chrome_debian/imbalanced', 'chrome_debian', 'devign'])
    parser.add_argument('--train_src', nargs='*', help='Path to the training source file.',
                        default=['./data/reveal_test/reveal_train_after_ggnn.json'])
    parser.add_argument('--test1_src', nargs='*', help='Path to the testing source file.',
                        default=['./data/reveal_test/reveal_test_after_ggnn.json'])
    parser.add_argument('--test2_src', nargs='*', help='Path to the testing source file.',
                        default=['./data/reveal_test/reveal_test_after_ggnn.json'])
    parser.add_argument('--test_model', type=str, help='use model to test.', default='reveal')
    parser.add_argument('--seed', type=int, default=1000)
    parser.add_argument('--epochs', type=int, default=30)
    parser.add_argument('--balance', type=str, default='False')

    parser.add_argument('--features', default='ggnn', choices=['ggnn', 'wo_ggnn'])
    parser.add_argument('--lambda1', default=0.5, type=float)
    parser.add_argument('--lambda2', default=0.001, type=float)
    # parser.add_argument('--baseline', action='store_true')
    # parser.add_argument('--baseline_balance', action='store_true')
    # parser.add_argument('--baseline_model', default='svm')
    parser.add_argument('--num_layers', default=1, type=int)
    # numpy.random.rand(1000)
    # torch.manual_seed(1000)
    args = parser.parse_args()
    dataset = args.dataset
    feature_name = args.features
    epochs = args.epochs

    # seed
    import dgl
    random.seed(args.seed)
    numpy.random.seed(args.seed)
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
    # if args.balance != 'False':
    #     balance = True
    # else:
    #     balance = False
    balance = args.balance
    output = os.path.join(args.dataset_root, args.dataset)

    model_dir = os.path.join(output, 'models-seed' + str(args.seed))
    if not os.path.exists(model_dir):
        os.makedirs(model_dir)
    # processed_data_path = os.path.join(output, 'processed.bin')

    # test_model_dir = os.path.join(args.dataset_root, args.test_model)
    # test_model_dir = os.path.join(test_model_dir, 'models-seed' + str(args.seed))
    test_model_dir = model_dir

    # ds = './'
    # parts = ['embed_devign_vulgen_reveal_train_after_ggnn.json']
    parts = args.train_src
    # output_dir = os.path.join(output, 'results_test')
    # if args.baseline:
    #     output_dir = os.path.join(output, 'baseline_' + args.baseline_model)
    #     if args.baseline_balance:
    #         output_dir += '_balance'
    #
    # if not os.path.exists(output_dir):
    #     os.mkdir(output_dir)
    # output_file_name = os.path.join(output_dir, dataset.replace('/', '_') + '-' + feature_name + '-')
    # if args.lambda1 == 0:
    #     assert args.lambda2 == 0
    #     output_file_name += 'cross-entropy-only-layers-' + str(args.num_layers) + '.tsv'
    # else:
    #     output_file_name += 'triplet-loss-layers-' + str(args.num_layers) + '.tsv'
    # output_file = open(output_file_name, 'w')
    features = []
    targets = []
    # for i in range(100):
    for part in parts:
        # json_data_file = open(ds + part)
        json_data_file = open(part)
        data = json.load(json_data_file)
        json_data_file.close()
        for d in data:
            while len(d['graph_feature']) < 200:
                d['graph_feature'].append(0.0)
            features.append(d['graph_feature'])
            targets.append(d['target'])
        del data
    train_X = numpy.array(features)
    train_Y = numpy.array(targets)
    # parts = ['embed_devign_vulgen_reveal_test_after_ggnn.json']
    parts = args.test1_src
    features = []
    targets = []

    # f=open("./syn_models/correct_"+str(0)+".json")
    # correct_ids = json.load(f)
    # f.close()
    id = 0
    for part in parts:
        json_data_file = open(part, encoding='utf8')
        data = json.load(json_data_file)
        json_data_file.close()
        for d in data:
            # if id in correct_ids:
            #    id+=1
            #    continue
            while len(d['graph_feature']) < 200:
                d['graph_feature'].append(0.0)
            features.append(d['graph_feature'])
            targets.append(d['target'])
            id += 1
        del data

    test1_X = numpy.array(features)
    test1_Y = numpy.array(targets)

    parts = args.test2_src
    features = []
    targets = []
    id = 0
    for part in parts:
        json_data_file = open(part, encoding='utf8')
        data = json.load(json_data_file)
        json_data_file.close()
        for d in data:
            # if id in correct_ids:
            #    id+=1
            #    continue
            while len(d['graph_feature']) < 200:
                d['graph_feature'].append(0.0)
            features.append(d['graph_feature'])
            targets.append(d['target'])
            id += 1
        del data

    test2_X = numpy.array(features)
    test2_Y = numpy.array(targets)

    print('Training Dataset', train_X.shape, train_Y.shape, numpy.sum(train_Y), sep='\t', file=sys.stderr)
    print('Testing1 Dataset', test1_X.shape, test1_Y.shape, numpy.sum(test1_Y), sep='\t', file=sys.stderr)
    print('Testing2 Dataset', test2_X.shape, test2_Y.shape, numpy.sum(test2_Y), sep='\t', file=sys.stderr)
    print('=' * 100, file=sys.stderr, flush=True)
    # import pdb
    # pdb.set_trace()
    f1_score = 0
    for tr in range(1):
        # train_X, test_X, train_Y, test_Y = train_test_split(X, Y, test_size=0.5)
        print(train_X.shape, train_Y.shape, test1_X.shape, test1_Y.shape, test2_X.shape, test2_Y.shape, sep='\t', file=sys.stderr, flush=True)
        # if args.baseline:
        #     model = SVMLearningAPI(True, args.baseline_balance, model_type=args.baseline_model)
        # else:
        # print("balance: ", args.balance, file=sys.stderr)
        model = RepresentationLearningModel(
            lambda1=args.lambda1, lambda2=args.lambda2, batch_size=128, print=True,
            num_epoch=epochs, max_patience=5, balance=balance,
            num_layers=args.num_layers
        )
        # saved_model = torch.load("./best.pt")
        # is_test = True
        # is_test = False
        if is_test:
            fp = os.path.join(test_model_dir, 'best.pt')
            f = open(fp, 'rb')
            obj = pickle.load(f)
            model.model = obj[0]
            model.dataset = obj[1]
            f.close()
        else:
            model.train(train_X, train_Y, test1_X, test1_Y, test2_X, test2_Y, model_dir)
            fp = os.path.join(model_dir, 'best.pt')
            #复原：
            f = open(fp, 'wb')
            pickle.dump([model.model, model.dataset], f)
            f.close()
            #复原
        # neg_metrics = []
        # avg_metrics = []
        # other_metrics = []
        # results = model.evaluate(test_X, test_Y, neg_metrics, avg_metrics, other_metrics)
        # predicts = model.predict_proba(test_X)
        # correct_ids = []
        # for id, predict in enumerate(predicts):
        #    if test_Y[id] == round(float(predict[0])):
        #        correct_ids.append(id)
        # import pdb
        # pdb.set_trace()
        # f=open("./reproduce_models/correct_"+str(tr)+".json",'w')
        # json.dump(correct_ids,f,indent=4)
        # f.close()
        # print(results['accuracy'], results['precision'], results['recall'], results['f1'], sep='\t', flush=True,
        #      file=output_file)

        # print(results['accuracy'], results['precision'], results['recall'], results['f1'])
        # print("pos testing result:", results['accuracy'], results['precision'], results['recall'], results['f1'])
        # print("neg testing result:", neg_metrics)
        # print("avg testing result:", avg_metrics)
        # print("auc: ", other_metrics[0], "mcc: ", other_metrics[1], "pos_g_m: ", other_metrics[2], "neg_g_m: ",
        #       other_metrics[3], "avg_g_m: ", other_metrics[4])
        # if results['f1']>f1_score:
        # f1_score = results['f1']
        # torch.save(model.model,'./reproduce_models/reproduce_'+str(tr)+'.pt')

    # output_file.close()
    pass
