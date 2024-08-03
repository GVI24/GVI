import os
import subprocess
import logging
import shutil

os.chdir('/root/reveal/devign')

class FlushHandler(logging.StreamHandler):
    def emit(self, record):
        super().emit(record)
        self.flush()

# 创建一个logger
logger = logging.getLogger('my_logger')
logger.setLevel(logging.INFO)

# 创建一个handler，用于写入stdout日志文件
stdout_handler = logging.FileHandler('log/preprocess.out', mode='w')
stdout_handler.setLevel(logging.INFO)

# 创建一个handler，用于写入stderr日志文件
stderr_handler = logging.FileHandler('log/preprocess.err', mode='w')
stderr_handler.setLevel(logging.ERROR)

# 再创建一个handler，用于输出到控制台
console_handler = FlushHandler()
console_handler.setLevel(logging.INFO)

# 定义handler的输出格式
formatter = logging.Formatter('==================== %(asctime)s - %(levelname)s: ==================== \n%(message)s')
stdout_handler.setFormatter(formatter)
stderr_handler.setFormatter(formatter)
console_handler.setFormatter(formatter)

# 给logger添加handler
logger.addHandler(stdout_handler)
logger.addHandler(stderr_handler)
logger.addHandler(console_handler)


def combine_vul_saf():
    # 合并生成的vul和采样来的saf
    input_gen_vul = "/root/reveal/devign/data/origin_input/reveal_gen/vulnerables.json"  # 以后只改这个
    input_gen_saf = "/root/reveal/devign/data/origin_input/reveal_gen/non-vulnerables.json"
    output = subprocess.run(
        "python -u ./data_preprocess/combine_json.py --input_gen_vul " + input_gen_vul + " --input_gen_saf " + input_gen_saf,
        shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

def combine_all():
    # 合并所有
    input_train = "/root/reveal/devign/data/origin_input/reveal_2.json"
    input_gen = "/root/reveal/devign/data/origin_input/reveal_2_gen.json"
    input_test = "/root/reveal/data/reveal_gen/devign_test.json"
    output = subprocess.check_output(
        "python ./data_preprocess/process_json.py --input_train " + input_train + " --input_gen " + input_gen + " --input_test " + input_test,
        # "python -u ./data_preprocess/process_json.py --input_train " + input_train + " --input_test " + input_test,
        shell=True)
    logging.info(output.decode('utf-8'))

def raw_code():
    # 生成raw_code
    input_path = "./data/combined.json"
    output = subprocess.check_output("python -u ./data_preprocess/read_json.py --input " + input_path, shell=True)
    o = subprocess.run('ls -l ./data/gen_test/raw_code | grep "^-" | wc -l', shell=True,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    logger.info(o.stdout.decode('utf-8'))
    logger.error(o.stderr.decode('utf-8'))

def joern_parse():
    # 生成parsed
    joern_out_path = "./parsed"
    if os.path.exists(joern_out_path):
        shutil.rmtree(joern_out_path)
    result = subprocess.run("bash ./data_preprocess/code-slicer/joern/joern-parse ./data/gen_test/raw_code", shell=True,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    logger.info(result.stdout.decode('utf-8'))
    logger.error(result.stderr.decode('utf-8'))

    # 删除joern_out_path/data/gen_test/raw_code/parsed下的nodes.csv和edges.csv文件
    nodes_csv_path = os.path.join(joern_out_path, "data/gen_test/raw_code/nodes.csv")
    edges_csv_path = os.path.join(joern_out_path, "data/gen_test/raw_code/edges.csv")
    if os.path.exists(nodes_csv_path):
        os.remove(nodes_csv_path)
    if os.path.exists(edges_csv_path):
        os.remove(edges_csv_path)

# ls -l ./parsed/data/gen_test/raw_code | grep "^d" | wc -l查文件夹数
# ls -l ./parsed/data/gen_test/raw_code | grep "^-" | wc -l查文件数

    # 把joern_out_path/data/gen_test/raw_code下的文件剪切到data_out_path下
    data_out_path = "./data/gen_test/parsed"
    if os.path.exists(data_out_path):
        shutil.rmtree(data_out_path)
    os.system("mkdir " + data_out_path)
    # 获取源目录
    source_dir = os.path.join(joern_out_path, "data/gen_test/raw_code")
    # 遍历源目录下的所有文件夹
    for dir_name in os.listdir(source_dir):
        source_folder = os.path.join(source_dir, dir_name)
        # 确保它是一个文件夹，而不是文件
        if os.path.isdir(source_folder):
            # 获取目标文件夹的完整路径
            target_folder = os.path.join(data_out_path, dir_name)
            # 如果目标文件夹已经存在，删除它
            if os.path.exists(target_folder):
                shutil.rmtree(target_folder)
            # 移动文件夹
            shutil.move(source_folder, target_folder)

    o1 = subprocess.run('ls -l ./data/gen_test/parsed | grep "^d" | wc -l', shell=True,
                          stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    o2 = subprocess.run('ls -l ./data/gen_test/parsed | grep "^-" | wc -l', shell=True,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    logger.info(o1.stdout.decode('utf-8'))
    logger.error(o1.stderr.decode('utf-8'))
    logger.info(o2.stdout.decode('utf-8'))
    logger.error(o2.stderr.decode('utf-8'))

    # 删除joern_out_path
    if os.path.exists(joern_out_path):
        shutil.rmtree(joern_out_path)

def processing_combined():
    # 执行processing_combined.py
    output = subprocess.run("python -u ./data_preprocess/processing_combined.py", shell=True, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE)
    logger.info(output.stdout.decode('utf-8'))
    logger.error(output.stderr.decode('utf-8'))

def split():
    # 执行preprocess_checker.py
    output = subprocess.run("python -u ./data_preprocess/preprocess_checker.py --input \
    ./data/origin_input/devign_test.json \
    ./data/origin_input/reveal_2.json \
    ./data/origin_input/reveal_2_gen.json",
                            shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    logger.info(output.stdout.decode('utf-8'))
    logger.error(output.stderr.decode('utf-8'))

if __name__ == '__main__':
    # combine_vul_saf()
    # combine_all()
    # raw_code()
    joern_parse()
    # processing_combined()# 直接执行命令
    # split()
    