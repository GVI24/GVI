import os
import json
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--input_train', type=str, nargs='+',default=['/root/reveal/devign/data/combined_gen.json'])
parser.add_argument('--input_gen', type=str, nargs='+',default=['/root/reveal/data/reveal_gen/train_generated_reveal.json'])
parser.add_argument('--input_test', type=str, nargs='+',default=['/root/reveal/data/reveal_gen/devign_test.json'])
args = parser.parse_args()
input_train = args.input_train[0]

input_test = args.input_test[0]


data1 = []
data2 = []
data3 = []
with open(input_train, 'r') as f:
    data1 = json.load(f)

if args.input_gen is not None:
    input_gen = args.input_gen[0]
    with open(input_gen, 'r') as f:
        data2 = json.load(f)

with open(input_test, 'r') as f:
    data3 = json.load(f)

with open("./data/combined.json", 'w') as f:
    json.dump(data1 + data2 + data3, f, indent=4)
    print(len(data1 + data2 + data3))
