import os
import json
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--input_gen_vul', type=str, nargs='+',default='/root/devign/data/origin_input/vulgen.json')
parser.add_argument('--input_gen_saf', type=str, nargs='+',default='/root/devign/data/origin_input/real_world_nonvul_912.json')
args = parser.parse_args()
input_gen_vul = args.input_gen_vul
input_gen_saf = args.input_gen_saf

# vul = []
# saf = []
# with open(input_gen_vul, 'r') as f:
#     vul = json.load(f)
# with open(input_gen_saf, 'r') as f:
#     saf = json.load(f)
#
# with open('/root/devign/data/combined_gen.json', 'w') as f:
#     json.dump(vul+saf, f, indent=4)

data1 = []
data2 = []
data3 = []
data4 = []
data5 = []
data6 = []
with open('/root/devign/data/origin_input/devign.json', 'r') as f:
    data1 = json.load(f)
with open('/root/devign/data/origin_input/real_world_nonvul_912.json', 'r') as f:
    data2 = json.load(f)
with open('/root/devign/data/origin_input/reveal.json', 'r') as f:
    data3 = json.load(f)
with open('/root/devign/data/origin_input/train_generated_3.json', 'r') as f:
    data4 = json.load(f)
with open('/root/devign/data/origin_input/vulgen.json', 'r') as f:
    data5 = json.load(f)
with open('/root/devign/data/origin_input/xen.json', 'r') as f:
    data6 = json.load(f)
with open('/root/devign/data/combined.json', 'w') as f:
    json.dump(data1+data2+data3+data4+data5+data6, f, indent=4)
