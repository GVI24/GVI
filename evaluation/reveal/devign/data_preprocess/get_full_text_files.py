import os
import json

def main(project):
    lst = []
    for file_name in os.listdir(f'./data/{project}/raw_code'):
        dic = {}
        if file_name.endswith('1.c'):
            with open(f'./data/{project}/raw_code/'+file_name, 'r') as f:
                code = f.read()
            dic['code'] = code
            dic['label'] = 1
            dic['file_name'] = file_name
            lst.append(dic)
        if file_name.endswith('0.c'):
            with open(f'./data/{project}/raw_code/'+file_name, 'r') as f:
                code = f.read()
            dic['code'] = code
            dic['label'] = 0
            dic['file_name'] = file_name
            lst.append(dic)

    with open(f'./data/{project}/{project}_cfg_full_text_files.json', 'w+') as f:
        json.dump(lst, f, indent=4)
        
if __name__ == "__main__":
    PROJECT = "gen_test"
    # for SPLIT_TYPE in ["train", "valid", "test"]:
    #     main(PROJECT, SPLIT_TYPE)
    main(PROJECT)