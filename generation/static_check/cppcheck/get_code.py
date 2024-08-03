import json
import os

file_path = "/root/reveal/static_check/cppcheck/raw_code"
if os.path.exists(file_path):
    shutil.rmtree(file_path)
os.makedirs(file_path)

with open('/root/reveal/data/reveal_z2/reveal_2_gen.json') as f:
    data = json.load(f)
    for item in data:
        file_name = item['file_name']
        file = os.path.join(file_path, file_name)
        with open(file, 'w') as f:
            f.write(item['code'])
