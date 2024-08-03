import os
import json
import argparse
import ijson
import glob
from tqdm import tqdm
from decimal import Decimal

def default(obj):
    if isinstance(obj, Decimal):
        return float(obj)
    raise TypeError("Object of type '%s' is not JSON serializable" % type(obj).__name__)

def load_filenames(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
    print_list_stats(data, os.path.basename(file_path))
    return {item['file_name'] for item in data}

def print_list_stats(data, name=""):
    count_vul = sum(item['label'] == 1 for item in data)
    print(f"{name}\tTotal: {len(data)}\tVulnerable: {count_vul}")

def process_shards(shard_files, filenames_sets, output_dir, shard_size=5000):
    output_files = {name: None for name in filenames_sets}
    shard_indices = {name: 0 for name in filenames_sets}
    stats = {name: {'total': 0, 'vulnerable': 0} for name in filenames_sets}

    def start_new_shard_file(dataset_name):
        if output_files[dataset_name]:
            output_files[dataset_name].write(']\n')
            output_files[dataset_name].close()
        shard_file_path = os.path.join(output_dir, f"{dataset_name}.shard{shard_indices[dataset_name]+1}")
        output_files[dataset_name] = open(shard_file_path, 'w')
        output_files[dataset_name].write('[')
        shard_indices[dataset_name] += 1
        return output_files[dataset_name]


    for shard_file in shard_files:
        print(f"Processing {shard_file}")
        with open(shard_file, 'r') as f:
            for obj in tqdm(ijson.items(f, 'item'), total=5000, desc=f"Reading {os.path.basename(shard_file)}", unit="item"):
                file_name = obj['file_name']
                for dataset_name, filenames_set in filenames_sets.items():
                    if file_name in filenames_set:
                        if stats[dataset_name]['total'] % shard_size == 0:
                            output_file = start_new_shard_file(dataset_name)
                        else:
                            output_file = output_files[dataset_name]
                            output_file.write(',\n')

                        json.dump(obj, output_file, default=default)
                        # output_file.write('\n')
                        stats[dataset_name]['total'] += 1
                        if obj['label'] == 1:
                            stats[dataset_name]['vulnerable'] += 1
                        # if stats[dataset_name]['total'] % shard_size == 0:
                        #     output_files[dataset_name].close()
                        #     output_files[dataset_name] = None
                            # shard_indices[dataset_name] += 1
                        break

    # Close any remaining open files and finalize JSON array
    for dataset_name, output_file in output_files.items():
        if output_file:
            output_file.write(']\n')
            output_file.close()

    # Print stats
    for dataset_name in filenames_sets:
        print(f"Finished processing for {dataset_name}. Total records: {stats[dataset_name]['total']}, Vulnerable: {stats[dataset_name]['vulnerable']}")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=str, default=['/root/my_eval/RQ1/devign/data/bigvul_mygen.json',
                                                      '/root/my_eval/RQ1/devign/data/devign_mygen.json',
                                                      '/root/my_eval/RQ1/devign/data/reveal_mygen.json'])
    # parser.add_argument('--input', type=str, default=['../dataset/eval_same_set/train_my_gen.json',
    #                                                   '../dataset/eval_same_set/test_my_gen.json'])
    # parser.add_argument('--input', type=str, default=['../dataset/eval_same_set/train_baseline.json',
    #                                                   '../dataset/eval_same_set/test_baseline.json'])
    # parser.add_argument('--input', type=str, default=['../data/split/same_set_my_gen.json'])
    # Create output directory if it does not exist
    output_dir = "../data/split"
    # if os.path.exists(output_dir):
    #     os.system(f"rm -rf {output_dir}")
    # os.makedirs(output_dir, exist_ok=True)

    key_mapping = {
        # 'generalization_my_gen.json': 'generalization_my_gen',
        'bigvul_mygen.json': 'bigvul_mygen',
        'devign_mygen.json': 'devign_mygen',
        'reveal_mygen.json': 'reveal_mygen'
    }
    filenames_dict = {}
    
    args = parser.parse_args()
    for item in args.input:
        filename = os.path.basename(item)
        key = key_mapping.get(filename, filename)
        print(f'filename: {filename}, key: {key}')
        filenames_dict[key] = load_filenames(item)

    # print(f'filenames_dict: {filenames_dict}')
    # assert 0

    # Get all shard files
    shard_files = sorted(glob.glob('/root/my_eval/RQ1/devign/code/data/output/gen_test/gen_test.json.shard*'))
    # shard_files_1 = glob.glob('../dataset/shard_generalization/train_baseline.shard*')
    # shard_files_2 = glob.glob('../dataset/shard_generalization/my_gen.shard*')
    # shard_files = sorted(shard_files_1 + shard_files_2)
    # shard_files = glob.glob('../dataset/shard_generalization/train_baseline.shard*')

    # Process shards and save the data
    process_shards(shard_files, filenames_dict, output_dir)





# import os
# import json
# from tqdm import tqdm
# import argparse
# import ijson
# import glob
# from decimal import Decimal
#
#
# parser = argparse.ArgumentParser()
# parser.add_argument('--input_train', type=str, default='/root/devign/data/origin_input/devign.json')
# parser.add_argument('--input_gen', type=str, default='/root/devign/data/origin_input/train_generated_3.json')
# parser.add_argument('--input_test', type=str, default='/root/devign/data/origin_input/reveal.json')
# args = parser.parse_args()
#
# input_train = args.input_train
# input_gen = args.input_gen
# input_test = args.input_test
#
# def default(obj):
#     if isinstance(obj, Decimal):
#         return float(obj)
#     raise TypeError("Object of type '%s' is not JSON serializable" % type(obj).__name__)
#
#
# def load_filenames(file_path):
#     with open(file_path, 'r') as f:
#         data = json.load(f)
#         print_list_stats(data, file_path)
#     return {item['file_name'] for item in data}
#
# def print_list_stats(data, name=""):
#     count_vul = sum(item['label'] == 1 for item in data)
#     print(f"{name}\tTotal: {len(data)}\tVulnerable: {count_vul}")
#
# def save_data_in_shards(data, file_path_prefix, shard_idx):
#     shard_filename = f"{file_path_prefix}.shard{shard_idx}"
#     print_list_stats(data, shard_filename)
#     with open(shard_filename, 'w') as f:
#         json.dump(data, f, indent=4, default=default)  # 使用 default 参数处理 Decimal
#     print(f"Saved {shard_filename}")
#
#
# def filter_and_save_shards(shard_dir, output_dir, filename_set, output_prefix):
#     shard_files = sorted(glob.glob(os.path.join(shard_dir, 'gen_test.json.shard*')))
#     shard_idx = 1
#     filtered_data = []
#     total_count = 0
#     total_vul = 0
#
#     for shard_file in tqdm(shard_files, desc=f"Processing shards for {output_prefix}"):
#         with open(shard_file, 'r') as f:
#             objects = ijson.items(f, 'item')
#             for obj in objects:
#                 if obj['file_name'] in filename_set:
#                     filtered_data.append(obj)
#                     total_count += 1
#                     if obj['label'] == 1:
#                         total_vul += 1
#                     if len(filtered_data) == 5000:
#                         save_data_in_shards(filtered_data, output_dir + output_prefix, shard_idx)
#                         filtered_data = []
#                         shard_idx += 1
#
#     if filtered_data:
#         save_data_in_shards(filtered_data, output_dir + output_prefix, shard_idx)
#
#     print(f"Finished {output_prefix}. Total: {total_count}, Vulnerable: {total_vul}")
#
# # Load the file names from input JSON
# print("Loading file names from inputs...")
# train_filenames = load_filenames(input_train)
# gen_filenames = load_filenames(input_gen)
# test_filenames = load_filenames(input_test)
#
#
# # Create output directory if it does not exist
# output_dir = "/root/devign/data/origin_output/"
# if os.path.exists(output_dir):
#     os.system(f"rm -rf {output_dir}")
# os.makedirs(output_dir, exist_ok=True)
#
# # Filter and save shards
# print("Filtering and saving shards...")
# filter_and_save_shards(shard_dir="/root/devign/data/output/gen_test",
#                        output_dir=output_dir,
#                        filename_set=train_filenames,
#                        output_prefix="train_baseline")
#
# filter_and_save_shards(shard_dir="/root/devign/data/output/gen_test",
#                        output_dir=output_dir,
#                        filename_set=gen_filenames,
#                        output_prefix="train_gen")
#
# filter_and_save_shards(shard_dir="/root/devign/data/output/gen_test",
#                        output_dir=output_dir,
#                        filename_set=test_filenames,
#                        output_prefix="test")
