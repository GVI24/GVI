import pandas as pd
import json as js
import re
import os, sys, string, re, glob
import subprocess
import tempfile
import pickle
from multiprocessing import Pool

def generate_prolog(testcase, id_num, project):
    # change joern home dir here
    joern_home = "./joern_bc/"
    tmp_dir = tempfile.TemporaryDirectory()
    short_filename = str(id_num) + ".cpp"
    with open(tmp_dir.name + "/" + short_filename, 'w') as f:
        f.write(testcase)
    # print(short_filename)
    subprocess.check_call(
        "cd " + joern_home + "&& ./joern-parse " + tmp_dir.name + " --out " + tmp_dir.name + "/cpg.bin.zip",
        shell=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.STDOUT)

    tree = subprocess.check_output(
        "cd "+joern_home +"&& ./joern --script joern_cfg_to_dot.sc --params cpgFile=" + tmp_dir.name + "/cpg.bin.zip",
        shell=True,
        universal_newlines=True)
    # subprocess.check_call(
    #     "cd " + joern_home + "&& ./joern-export " + tmp_dir.name + "/cpg.bin.zip" + " --repr pdg --out " + os.getcwd() + "/pdg/" + project + "/" + str(
    #         id_num),shell=True)
    # pos = tree.find("% FEATURE")
    pos = tree.find("digraph g")
    print(pos)
    if pos > 0:
        tree = tree[pos:]
    tmp_dir.cleanup()
    return tree


def gen(_data,_i, project):
    # change file name here

    file_name = f'./processed_data/raw_{project}/{_i}.pkl'
    # if os.path.isfile(file_name):
    #     return
    print(f'IN -> {_i}')
    try:
        tree = generate_prolog(_data[1], _i, "Fan")
        _data.append(tree)
        with open(file_name, 'wb') as f:
            pickle.dump(_data, f)
    except Exception as e:
        print(f'fail -> {_i}, {e}')

if __name__ == '__main__':
    Rule1 = "\/\*[\s\S]*\*\/"
    Rule2 = "\/\/.*"

    # dataset = pd.read_csv("")
    # print(dataset.info())
    # print(dataset.target.value_counts())
    # data_storage = []
    # for i, j in dataset.iterrows():
    #     code = j["processed_func"]
    #     target = j["target"]
    #     lines = j["flaw_line_index"]
    #     code = re.sub(Rule1, "", re.sub(Rule2, "", code))
    #     data_storage.append([int(target), code, lines])
    # pool = Pool()
    # pool.starmap(gen, zip(data_storage, range(0, len(data_storage)), ["reveal_test"] * len(data_storage)))

    # projects = ['', '']
    # for project in projects:
    #     df = pd.read_json(f"./raw_data/{project}.jsonl", orient="records", lines=True)
    #     print(df.info())
    #     print(df.target.value_counts())
    #     df_storage = []
    #     for i, j in df.iterrows():
    #         code = j["func"]
    #         target = j["target"]
    #         code = re.sub(Rule1, "", re.sub(Rule2, "", code))
    #         df_storage.append([int(target), code])
    #     file_path = f'./processed_data/raw_{project}/'
    #     if not os.path.exists(file_path):
    #         os.makedirs(file_path)
    #     pool = Pool()
    #     pool.starmap(gen, zip(df_storage, range(0, len(df_storage)), [project]*len(df_storage)) )

    

    # file_path = f''
    # data_filtered = []
    # for file in glob.glob(file_path + "*.pkl"):
    #     with open(file, 'rb') as f:
    #         data = pickle.load(f)
    #         data_filtered.extend([(data[0], data[1], data[2])])
    #
    # df = pd.DataFrame(data_filtered, columns=['bug', 'code', 'trees'])
    # df.to_csv('processed_data/all_vulgen_data.csv', index=True)
    # print(df.info())
    
    file_path = f''
    data_filtered = []
    for file in glob.glob(file_path + "*.pkl"):
        with open(file, 'rb') as f:
            data = pickle.load(f)
            data_filtered.extend([(data[0], data[1], data[2], data[3])])
    df = pd.DataFrame(data_filtered, columns=['bug', 'code', 'lines', 'trees'])
    df.to_csv('processed_data/all_reveal_test_data.csv', index=True)
    print(df.info())
    
    
