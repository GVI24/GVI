import os
import json
import argparse
import shutil
parser = argparse.ArgumentParser()
parser.add_argument('--input', type=str, nargs='+',default=['/root/reveal/devign/data/combined.json'])
args = parser.parse_args()
input = args.input[0]

file_path = "./data/gen_test/raw_code"
if os.path.exists(file_path):
    shutil.rmtree(file_path)
os.makedirs(file_path)

with open(input, 'r')as f:
    data = json.load(f)
    for item in data:
        file_name = item['file_name']
        file = os.path.join(file_path, file_name)
        with open(file, 'w') as f:
            f.write(item['code'])

