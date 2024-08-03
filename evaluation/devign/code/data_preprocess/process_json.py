import os
import json
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--input_train', type=str, nargs='+',default=['/root/devign/data/devign.json'])
parser.add_argument('--input_gen', type=str, nargs='+',default=['/root/devign/data/train_generated_3.json'])
parser.add_argument('--input_test', type=str, nargs='+',default=['/root/devign/data/reveal.json'])
args = parser.parse_args()
input_train = args.input_train[0]
input_gen = args.input_gen[0]
input_test = args.input_test[0]


data1 = []
data2 = []
data3 = []
with open(input_train, 'r') as f:
    data1 = json.load(f)

with open(input_gen, 'r') as f:
    data2 = json.load(f)

with open(input_test, 'r') as f:
    data3 = json.load(f)

index = 0
for i in data1:
    i['id'] = index
    i['file_name'] = str(index) + '_' + i['file_name']
    index += 1
for i in data2:
    i['id'] = index
    i['file_name'] = str(index) + '_' + i['file_name']
    index += 1
for i in data3:
    i['id'] = index
    i['file_name'] = str(index) + '_' + i['file_name']
    index += 1

with open("/root/my_eval/RQ1/devign/data/bigvul_mygen.json", 'w') as f:
    json.dump(data1, f, indent=4)

with open("/root/my_eval/RQ1/devign/data/devign_mygen.json", 'w') as f:
    json.dump(data2, f, indent=4)

with open("/root/my_eval/RQ1/devign/data/reveal_mygen.json", 'w') as f:
    json.dump(data3, f, indent=4)

with open("/root/my_eval/RQ1/devign/dataset/combined.json", 'w') as f:
    json.dump(data1 + data2 + data3, f, indent=4)
    print(index)
