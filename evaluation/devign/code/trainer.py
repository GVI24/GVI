import copy
from sys import stderr

import numpy as np
import torch
from sklearn.metrics import f1_score, precision_score, recall_score, accuracy_score
# from sklearn.metrics import accuracy_score as acc, precision_score as pr, recall_score as rc, f1_score as f1

from tqdm import tqdm
import json
from utils import debug


def evaluate_loss(model, loss_function, num_batches, data_iter, cuda=False):
    model.eval()
    with torch.no_grad():
        _loss = []
        all_predictions, all_targets = [], []
        for _ in range(num_batches):
            names, graph, targets = data_iter()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            batch_loss = loss_function(predictions, targets)
            _loss.append(batch_loss.detach().cpu().item())
            predictions = predictions.detach().cpu()
            if predictions.ndim == 2:
                all_predictions.extend(np.argmax(predictions.numpy(), axis=-1).tolist())
            else:
                all_predictions.extend(
                    predictions.ge(torch.ones(size=predictions.size()).fill_(0.5)).to(
                        dtype=torch.int32).numpy().tolist()
                )
            all_targets.extend(targets.detach().cpu().numpy().tolist())
        model.train()
        return np.mean(_loss).item(), f1_score(all_targets, all_predictions) * 100
    pass


def get_embeddings(model, loss_function, num_batches, data_iter, after_ggnn_file):
    model.eval()
    after_ggnn = []
    with torch.no_grad():
        _loss = []
        all_predictions, all_targets = [], []
        for _ in range(num_batches):
            names, graph, targets = data_iter()
            targets = targets.cuda()
            embeddings = []
            predictions = model(graph, cuda=True, embeddings=embeddings)
            # import pdb
            # pdb.set_trace()
            for iii, embedding in enumerate(embeddings[0]):
                obj = {}
                # obj["name"] = names[iii]
                obj["target"] = int(targets[iii].tolist())
                obj["graph_feature"] = embedding
                after_ggnn.append(obj)
            batch_loss = loss_function(predictions, targets)
            _loss.append(batch_loss.detach().cpu().item())
            predictions = predictions.detach().cpu()
            if predictions.ndim == 2:
                all_predictions.extend(np.argmax(predictions.numpy(), axis=-1).tolist())
            else:
                all_predictions.extend(
                    predictions.ge(torch.ones(size=predictions.size()).fill_(0.5)).to(
                        dtype=torch.int32).numpy().tolist()
                )
            all_targets.extend(targets.detach().cpu().numpy().tolist())
        model.train()
        f = open(after_ggnn_file, "w")
        json.dump(after_ggnn, f)
        f.close()

        return accuracy_score(all_targets, all_predictions) * 100, \
               precision_score(all_targets, all_predictions) * 100, \
               recall_score(all_targets, all_predictions) * 100, \
               f1_score(all_targets, all_predictions) * 100
    pass


def get_corrects(model, loss_function, num_batches, data_iter, correct_file):
    model.eval()
    after_ggnn = []
    correct_names = []
    with torch.no_grad():
        _loss = []
        all_predictions, all_targets = [], []
        all_names = []
        for _ in range(num_batches):
            names, graph, targets = data_iter()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            '''
            for iii,embedding in enumerate(embeddings[0]):
                obj={}
                obj["name"] = names[iii]
                obj["target"] = int(targets[iii].tolist())
                obj["graph_feature"] = embedding
                after_ggnn.append(obj)
            '''
            batch_loss = loss_function(predictions, targets)
            _loss.append(batch_loss.detach().cpu().item())
            predictions = predictions.detach().cpu()
            if predictions.ndim == 2:
                all_predictions.extend(np.argmax(predictions.numpy(), axis=-1).tolist())
            else:
                all_predictions.extend(
                    predictions.ge(torch.ones(size=predictions.size()).fill_(0.5)).to(
                        dtype=torch.int32).numpy().tolist()
                )
            all_targets.extend(targets.detach().cpu().numpy().tolist())
            all_names.extend(names)
        for iii in range(len(all_names)):
            if int(all_targets[iii]) == int(all_predictions[iii]):
                correct_names.append(all_names[iii])

        model.train()
        f = open(correct_file, "w")
        json.dump(correct_names, f, indent=4)
        f.close()

        return accuracy_score(all_targets, all_predictions) * 100, \
               precision_score(all_targets, all_predictions) * 100, \
               recall_score(all_targets, all_predictions) * 100, \
               f1_score(all_targets, all_predictions) * 100
    pass


def evaluate_metrics(model, loss_function, num_batches, data_iter, neg_metrics=[], avg_metrics=[], other_metrics=[]):
    model.eval()
    with torch.no_grad():
        _loss = []
        all_predictions, all_targets = [], []
        for _ in range(num_batches):
            names, graph, targets = data_iter()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            batch_loss = loss_function(predictions, targets)
            _loss.append(batch_loss.detach().cpu().item())
            predictions = predictions.detach().cpu()
            # import pdb
            # pdb.set_trace()
            if predictions.ndim == 2:
                all_predictions.extend(np.argmax(predictions.numpy(), axis=-1).tolist())
            else:
                all_predictions.extend(
                    predictions.ge(torch.ones(size=predictions.size()).fill_(0.5)).to(
                        dtype=torch.int32).numpy().tolist()
                )
            all_targets.extend(targets.detach().cpu().numpy().tolist())
        model.train()
        tp = 0
        fp = 0
        tn = 0
        fn = 0
        for i, prediction in enumerate(all_predictions):
            if prediction == 1 and all_targets[i] == 1:
                tp += 1
            if prediction == 1 and all_targets[i] == 0:
                fp += 1
            if prediction == 0 and all_targets[i] == 0:
                tn += 1
            if prediction == 0 and all_targets[i] == 1:
                fn += 1
        # neg_acc = (tn+tp)/(tn+tp+fn+fp)*100
        # neg_prec = (tn)/(tn+fn)*100
        # neg_recall = (tn)/(tn+fp)*100
        # neg_f1 = 2*neg_prec*neg_recall/(neg_prec+neg_recall)

        pos_acc = accuracy_score(all_targets, all_predictions) * 100
        pos_prec = precision_score(all_targets, all_predictions) * 100
        pos_recall = recall_score(all_targets, all_predictions) * 100
        pos_f1 = f1_score(all_targets, all_predictions) * 100

        neg_acc = accuracy_score(all_targets, all_predictions) * 100
        neg_prec = precision_score(all_targets, all_predictions, pos_label=0) * 100
        neg_recall = recall_score(all_targets, all_predictions, pos_label=0) * 100
        neg_f1 = f1_score(all_targets, all_predictions, pos_label=0) * 100

        avg_acc = accuracy_score(all_targets, all_predictions) * 100
        avg_prec = precision_score(all_targets, all_predictions, average='macro') * 100
        avg_recall = recall_score(all_targets, all_predictions, average='macro') * 100
        avg_f1 = f1_score(all_targets, all_predictions, average='macro') * 100

        from sklearn.metrics import roc_auc_score, matthews_corrcoef
        auc = roc_auc_score(all_targets, all_predictions)
        mcc = matthews_corrcoef(all_targets, all_predictions)

        from math import sqrt
        pos_g_measure = sqrt(pos_prec * pos_recall)
        neg_g_measure = sqrt(neg_prec * neg_recall)
        avg_g_measure = sqrt(avg_prec * avg_recall)

        neg_metrics.extend([neg_acc, neg_prec, neg_recall, neg_f1])
        avg_metrics.extend([avg_acc, avg_prec, avg_recall, avg_f1])
        other_metrics.extend([auc, mcc, pos_g_measure, neg_g_measure, avg_g_measure])

        return pos_acc, \
            pos_prec, \
            pos_recall, \
            pos_f1


def train_2000(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every=50, max_patience=5):
    debug('Start Training')
    log_every = dev_every
    train_losses = []
    best_model = None
    patience_counter = 0
    best_f1 = 0
    try:
        for step_count in range(max_steps):
            model.train()
            model.zero_grad()
            names, graph, targets = dataset.get_next_train_batch()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            batch_loss = loss_function(predictions, targets)
            # if log_every is not None and (step_count % log_every == log_every - 1):
            #     debug('Step %d\t\tTrain Loss %10.3f' % (step_count, batch_loss.detach().cpu().item()))
            train_losses.append(batch_loss.detach().cpu().item())
            batch_loss.backward()
            optimizer.step()
            if step_count % dev_every == (dev_every - 1):
                # train_loss, train_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)
                # debug('Train Loss: %0.2f\tTrain F1: %0.2f' % (train_loss, train_f1))
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)
                # debug('Train Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),dataset.get_next_test_batch)
                # debug('Test Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # valid_f1 = f1
                # valid_f1=train_f1
                # valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),
                #                                     dataset.get_next_train_batch)
                # if True or valid_f1 > best_f1:
                # patience_counter = 0
                # best_f1 = valid_f1
                # best_model = copy.deepcopy(model)
                _save_file = open(save_path + '-model.bin' + str(step_count), 'wb')
                torch.save(model, _save_file)
                _save_file.close()

                # else:
                #    patience_counter += 1
                # debug('Step %d\t\tTrain Loss %10.3f\tTest Loss%10.3f\tf1: %5.2f\tPatience %d' % (
                #    step_count, np.mean(train_losses).item(), valid_loss, valid_f1, patience_counter))
                # debug('Step %d\t\tTrain Loss %10.3f\tTrain Loss%10.3f\tf1: %5.2f\tPatience %d' % (step_count, np.mean(train_losses).item(), train_loss, train_f1, patience_counter))
                # debug('Step %d' % (step_count))
                acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),
                                                   dataset.get_next_train_batch)
                debug(
                    'Step %d\tTest Accuracy:  %6.3f \t Test Precision:  %6.3f \t Test Recall: %6.3f \t Test F1:  %5.2f' % (
                        step_count, acc, pr, rc, f1))
                acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
                                                   dataset.get_next_test_batch)
                debug(
                    'Step %d\tTest Accuracy:  %6.3f \t Test Precision:  %6.3f \t Test Recall: %6.3f \t Test F1:  %5.2f' % (
                        step_count, acc, pr, rc, f1))

                debug('=' * 100)
                train_losses = []
                # if patience_counter == max_patience:
                if step_count > max_steps:
                    break
    except KeyboardInterrupt:
        debug('Training Interrupted by user!')

    # if best_model is not None:
    #    _save_file = open(save_path + '-model.bin', 'rb')
    #    model = torch.load(_save_file)
    #    _save_file.close()
    # model.load_state_dict(best_model)
    # _save_file = open(save_path + '-model.bin', 'wb')
    # torch.save(model, _save_file)
    # _save_file.close()
    acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
                                       dataset.get_next_test_batch)
    debug('%s\tTest Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (save_path, acc, pr, rc, f1))
    debug('=' * 100)
    return model


def train_20(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every=50, max_patience=5):
    debug('Start Training')
    max_steps = 1000000
    train_losses = []
    best_model = None
    patience_counter = 0
    best_f1 = 0
    try:
        for step_count in range(max_steps):
            model.train()
            model.zero_grad()
            names, graph, targets = dataset.get_next_train_batch()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            batch_loss = loss_function(predictions, targets)
            if log_every is not None and (step_count % log_every == log_every - 1):
                debug('Step %d\t\tTrain Loss %10.3f' % (step_count, batch_loss.detach().cpu().item()))
            train_losses.append(batch_loss.detach().cpu().item())
            batch_loss.backward()
            optimizer.step()
            if step_count % dev_every == (dev_every - 1):
                # train_loss, train_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)

                # neg_metrics = []
                # avg_metrics = []
                # other_metrics = []
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch, neg_metrics, avg_metrics, other_metrics)
                # debug('Train Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # print("pos testing result:", acc, pr, rc, f1)
                # print("neg testing result:", neg_metrics)
                # print("avg testing result:", avg_metrics)
                # print("auc: ", other_metrics[0], "mcc: ", other_metrics[1], "pos_g_m: ", other_metrics[2], "neg_g_m: ",
                #       other_metrics[3], "avg_g_m: ", other_metrics[4])

                # debug('Train Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),dataset.get_next_test_batch)
                # debug('Test Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # valid_f1 = f1
                # valid_f1=train_f1

                valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),
                                                     dataset.get_next_train_batch)
                # valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_valid_batch(),
                #                                      dataset.get_next_valid_batch)
                if valid_f1 > best_f1:
                    patience_counter = 0
                    best_f1 = valid_f1
                    best_model = copy.deepcopy(model)
                    _save_file = open(save_path + '-model.bin' + str(step_count), 'wb')
                    torch.save(model, _save_file)
                    _save_file.close()
                else:
                    patience_counter += 1
                debug('Step %d\tTrain Loss:      %6.3f \t Valid Loss:  %6.3f \t Valid F1: %5.2f \t Patience: %d' % (
                    step_count, np.mean(train_losses).item(), valid_loss, valid_f1, patience_counter))

                acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
                                                   dataset.get_next_test_batch)
                debug('Step %d\tTest Precision:  %6.3f \t Test Recall: %6.3f \t Test F1:  %5.2f' % (
                step_count, pr, rc, f1))

                # debug('Step %d\t\tTrain Loss %10.3f\tTrain Loss%10.3f\tf1: %5.2f\tPatience %d' % (step_count, np.mean(train_losses).item(), train_loss, train_f1, patience_counter))
                # debug('Step %d' % (step_count))
                debug('=' * 100)
                train_losses = []
                if patience_counter == max_patience:
                    # if step_count>max_steps:
                    break
    except KeyboardInterrupt:
        debug('Training Interrupted by user!')

    if best_model is not None:
        #    _save_file = open(save_path + '-model.bin', 'rb')
        #    model = torch.load(_save_file)
        #    _save_file.close()
        #     model.load_state_dict(best_model)
        _save_file = open(save_path + '-model.bin', 'wb')
        torch.save(model, _save_file)
        _save_file.close()
    acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
                                       dataset.get_next_test_batch)
    debug('%s\tTest Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (save_path, acc, pr, rc, f1))
    debug('=' * 100)
    return model


def train_valid(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every=50,
                max_patience=5):
    debug('Start Training')
    max_steps = 1000000
    train_losses = []
    best_model = None
    patience_counter = 0
    best_f1 = 0
    try:
        for step_count in range(max_steps):
            model.train()
            model.zero_grad()
            names, graph, targets = dataset.get_next_train_batch()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)
            batch_loss = loss_function(predictions, targets)
            if log_every is not None and (step_count % log_every == log_every - 1):
                debug('Step %d\t\tTrain Loss %10.3f' % (step_count, batch_loss.detach().cpu().item()))
            train_losses.append(batch_loss.detach().cpu().item())
            batch_loss.backward()
            optimizer.step()
            if step_count % dev_every == (dev_every - 1):
                # train_loss, train_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)

                # neg_metrics = []
                # avg_metrics = []
                # other_metrics = []
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch, neg_metrics, avg_metrics, other_metrics)
                # print("pos testing result:", acc, pr, rc, f1)
                # print("neg testing result:", neg_metrics)
                # print("avg testing result:", avg_metrics)
                # print("auc: ", other_metrics[0], "mcc: ", other_metrics[1], "pos_g_m: ", other_metrics[2], "neg_g_m: ",
                #       other_metrics[3], "avg_g_m: ", other_metrics[4])

                # debug('Train Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),dataset.get_next_test_batch)
                # debug('Test Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))
                # valid_f1 = f1
                # valid_f1=train_f1

                # valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),
                #                                      dataset.get_next_train_batch)
                valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_valid_batch(),
                                                     dataset.get_next_valid_batch)
                if valid_f1 > best_f1:
                    patience_counter = 0
                    best_f1 = valid_f1
                    best_model = copy.deepcopy(model)
                    _save_file = open(save_path + '-model.bin' + str(step_count), 'wb')
                    torch.save(model, _save_file)
                    _save_file.close()
                else:
                    patience_counter += 1
                debug('Step %d\t\tTrain Loss %10.3f\tTest Loss%10.3f\tf1: %5.2f\tPatience %d' % (
                    step_count, np.mean(train_losses).item(), valid_loss, valid_f1, patience_counter))
                # debug('Step %d\t\tTrain Loss %10.3f\tTrain Loss%10.3f\tf1: %5.2f\tPatience %d' % (step_count, np.mean(train_losses).item(), train_loss, train_f1, patience_counter))
                # debug('Step %d' % (step_count))
                debug('=' * 100)
                train_losses = []
                if patience_counter == max_patience:
                    # if step_count>max_steps:
                    break
    except KeyboardInterrupt:
        debug('Training Interrupted by user!')

    if best_model is not None:
        #    _save_file = open(save_path + '-model.bin', 'rb')
        #    model = torch.load(_save_file)
        #    _save_file.close()
        #     model.load_state_dict(best_model)
        _save_file = open(save_path + '-model.bin', 'wb')
        torch.save(model, _save_file)
        _save_file.close()
    acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test_batch(),
                                       dataset.get_next_test_batch)
    debug('%s\tTest Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (save_path, acc, pr, rc, f1))
    debug('=' * 100)
    return model


def train(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every, max_patience,
          train_mode):
    if train_mode == 'step_2000':
        # return train_2000(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every, max_patience)
        return train_2000_ori(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every,
                              max_patience)
    elif train_mode == 'patience_20':
        return train_20(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every,
                        max_patience)
    elif train_mode == 'patience_20_valid':
        return train_valid(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every,
                           max_patience)
    else:
        raise NotImplementedError('Unknown training mode %s' % train_mode)


def train_2000_ori(model, dataset, max_steps, dev_every, loss_function, optimizer, save_path, log_every=50,
                   max_patience=5):
    debug('Start Training')
    train_losses = []
    best_model = None
    patience_counter = 0
    best_f1 = 0

    # max_steps = 2600
    # max_steps = 1400
    # max_steps = 2800
    # class_weights = torch.tensor([0.9389, 1.0611]).cuda()
    # class_weights = torch.tensor([0.94, 1.06]).cuda()
    # class_weights = torch.tensor([1.0, 6658/1658]).cuda()
    # class_weights = torch.tensor([0.3987, 1.6013]).cuda()
    # class_weights = torch.tensor([1.0, 16311/6311]).cuda()
    class_weights = torch.tensor([1.0, 1.0]).cuda()
    debug('Weights : %s' % class_weights)
    try:
        for step_count in tqdm(range(max_steps)):
            model.train()
            model.zero_grad()
            names, graph, targets = dataset.get_next_train_batch()
            targets = targets.cuda()
            predictions = model(graph, cuda=True)

            # 使用targets.long()作为索引来从class_weights中选择元素
            # 如果class_weights是[1.0, 2.0]，targets是[0, 1, 0, 1]
            # 那么weights就会是[1.0, 2.0, 1.0, 2.0]
            weights = class_weights[targets.long()]
            weighted_targets = targets * weights
            batch_loss = loss_function(predictions, weighted_targets)

            # batch_loss = loss_function(predictions, targets)
            if log_every is not None and (step_count % log_every == log_every - 1):
                debug('Step %d\t\tTrain Loss %10.3f' % (step_count, batch_loss.detach().cpu().item()))
            # train_losses.append(batch_loss.detach().cpu().item())
            batch_loss.backward()
            optimizer.step()

            # optimizer.zero_grad()
            # batch_loss.backward()
            # optimizer.first_step(zero_grad=True)
            # # debug('loss1: %s' % batch_loss.detach().cpu().item())
            # predictions = model(graph, cuda=True)
            # batch_loss = loss_function(predictions, targets)
            # # train_losses.append(batch_loss.detach().cpu().item())
            # batch_loss.backward()
            # optimizer.second_step(zero_grad=True)
            # # debug('loss2: %s' % batch_loss.detach().cpu().item())

            if step_count % dev_every == (dev_every - 1):
            # if step_count == max_steps - 1:
                # train_loss, train_f1 = evaluate_loss(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)

                # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),dataset.get_next_train_batch)
                # debug('Train Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))

                # 这里
                acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test1_batch(),dataset.get_next_test1_batch)
                debug('Test1 Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))

                acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_test2_batch(),dataset.get_next_test2_batch)
                debug('Test2 Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (acc, pr, rc, f1))


                # valid_f1 = f1
                # valid_f1=train_f1
                # valid_loss, valid_f1 = evaluate_loss(model, loss_function, dataset.initialize_test_batch(),
                #                                     dataset.get_next_test_batch)
                # if True or valid_f1 > best_f1:
                # patience_counter = 0
                # best_f1 = valid_f1
                # best_model = copy.deepcopy(model)

                # 这里
                _save_file = open(save_path + '-model.bin' + str(step_count), 'wb')
                torch.save(model, _save_file)
                _save_file.close()

                # else:
                #    patience_counter += 1
                # debug('Step %d\t\tTrain Loss %10.3f\tTest Loss%10.3f\tf1: %5.2f\tPatience %d' % (
                #    step_count, np.mean(train_losses).item(), valid_loss, valid_f1, patience_counter))
                # debug('Step %d\t\tTrain Loss %10.3f\tTrain Loss%10.3f\tf1: %5.2f\tPatience %d' % (step_count, np.mean(train_losses).item(), train_loss, train_f1, patience_counter))
                debug('Step %d' % (step_count))
                debug('=' * 100)
                train_losses = []
                # if patience_counter == max_patience:
                if step_count > max_steps:
                    break
    except KeyboardInterrupt:
        debug('Training Interrupted by user!')

    # if best_model is not None:
    #    _save_file = open(save_path + '-model.bin', 'rb')
    #    model = torch.load(_save_file)
    #    _save_file.close()
    # model.load_state_dict(best_model)
    _save_file = open(save_path + '-model.bin', 'wb')
    torch.save(model, _save_file)
    _save_file.close()
    # acc, pr, rc, f1 = evaluate_metrics(model, loss_function, dataset.initialize_train_batch(),
    #                                    dataset.get_next_train_batch)
    # debug('%s\tTest Accuracy: %0.2f\tPrecision: %0.2f\tRecall: %0.2f\tF1: %0.2f' % (save_path, acc, pr, rc, f1))
    debug('=' * 100)
    return model