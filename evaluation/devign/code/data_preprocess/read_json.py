import os
import json
import argparse
import shutil
parser = argparse.ArgumentParser()
parser.add_argument('--input', type=str, nargs='+',default=['./data/devign.json'])
args = parser.parse_args()
input = args.input[0]

file_path = "./data/gen_test/raw_code"
if os.path.exists(file_path):
    shutil.rmtree(file_path)
os.makedirs(file_path)

# file_path2 = "./data/gen_test/raw_code_joern"
# if os.path.exists(file_path2):
#     shutil.rmtree(file_path2)
# os.makedirs(file_path2)

with open(input, 'r')as f:
    data = json.load(f)
    for item in data:
        file_name = item['file_name']
        file = os.path.join(file_path, file_name)
        with open(file, 'w') as f:
            f.write(item['code'])

# index = 0
# with open(input, 'r')as f:
#     data = json.load(f)
#     for item in data:
#         file_name = item['file_name']
#         dir=os.path.join(file_path2, str(index))
#         os.makedirs(dir)
#         file = os.path.join(dir, file_name)
#         with open(file, 'w') as f:
#             f.write(item['code'])
#
#         index += 1