import glob
import json
import os
import re
from sklearn.metrics import f1_score
import config

origin_data = config.origin_data
gen_output_root = config.gen_output_root
gen_output_result_root = config.gen_output_result_root
gen_combine_output = config.gen_combine_output
rm_comments_output = config.rm_comments_output


def extract(context, mode):
    matches = []
    if mode == 'text':
        pattern = r'```c\n(.+?)\n```'
        matches = re.findall(pattern, context, re.DOTALL)
    elif mode == 'example':
        # pattern = r'// Example \d+.*?\n(.*?)(?=// Example \d+|\Z)'
        match_list = [
            "// Example \d+",
            "//Example \d+",
            "// Example Function \d+",
            "// Example Vulnerable Function \d+",
            "// \d+. Example",
            "// Function \d+",
            "// vulnerable function \d+",
            "// Vulnerable function \d+",
            "// Vulnerable function \#\d+",
            "// Vulnerable functions example \d+",
            "// Vulnerable Function \d+",
            "// Vulnerable function example \d+",
            "// Vulnerable Function Example \d+",
            "// \d+. Vulnerable Function",
            "// Vulnerable example \d+",
            "// Vulnerable Example \d+",
            "// Vulnerable C Function Example \d+",
            "// Similar Example \d+",
            "/\* Example \d+ \*/",
            "/\* Example \d+: .*? \*/",
            "/\* Vulnerable Function \d+ \*/",
            "/\* Vulnerable Function \d+: .*? \*/",
            "/\* Vulnerable function \d+: .*? \*/",
            "/\* Vulnerable function example \d+ .*?\*/",
            "/\* Vulnerable Function Example \d+ .*?\*/",
            "/\*.*?Function \d+: .*? \*/",
            "/\*.*?Example \d+: .*? \*/",
        ]
        for match in match_list:
            pattern = rf'{match}.*?\n(.*?)(?={match}|\Z)'

            tmp_matches = re.findall(pattern, context, re.DOTALL)
            if len(tmp_matches) > 0:
                matches = tmp_matches
                break

    return matches


def find_error_position(file_path, error_position):
    with open(file_path, 'rb') as f:
        f.seek(max(0, error_position - 3000))  # Go a bit before the error position
        data = f.read(3000)  # Read some bytes around the error position
        for encoding in ('utf-8', 'iso-8859-1'):  # Try some encodings
            try:
                print(f"Decoding with {encoding}: {data.decode(encoding)}")
            except UnicodeDecodeError:
                print(f"Cannot decode with {encoding}")

# find_error_position('output_data/chain_reveal_4/294/1870_1.c', 3131)


# def parse_output():
#     dirs = os.listdir(gen_output_root)
#     gen = []
#     count = 0
#     error = 0
#     for i in range(0, len(dirs)):
#         # if i != 0:
#         #     continue
#         dir = os.path.join(gen_output_root, str(i))
#         files = os.listdir(dir)
#         for file in files:
#             if not file.endswith('.c'):  # Skip files that are not .c files
#                 continue
#             file_path = os.path.join(dir, file)
#             with open(file_path, 'r') as f:
#                 try:
#                     context = f.read()
#                 except UnicodeDecodeError as e:
#                     print(f'{file_path}:\tUnicodeDecodeError, {e}')
#                     continue
#                 matches = extract(context, 'text')
#                 if len(matches) == 5 or \
#                         len(matches) == 6 or \
#                         len(matches) == 7 or \
#                         len(matches) == 8:
#                     for num, match in enumerate(matches[-4:]):
#                         file = str(i) + '_' + str(num) + '_1.c'
#                         ex = {
#                             'id': count,
#                             'file_name': file,
#                             'file_path': file_path,
#                             'code': match,
#                             'label': 1
#                         }
#                         count += 1
#                         gen.append(ex)
#                 elif len(matches) == 2 or len(matches) == 3:
#                     match = matches[-1]
#                     # if 'int main() {' in match or \
#                     #         'int main(int argc, char *argv[]) {' in match or \
#                     #         'int main(int argc, char **argv) {' in match :
#                     #     print(f'{i}:\tmain')
#                     #     continue
#                     examples = extract(match, 'example')
#                     if len(examples) == 2 or len(examples) == 4 or len(examples) == 5:
#                         for num, example in enumerate(examples):
#                             file = str(i) + '_' + str(num) + '_1.c'
#                             ex = {
#                                 'id': count,
#                                 'file_name': file,
#                                 'file_path': file_path,
#                                 'code': example,
#                                 'label': 1
#                             }
#                             count += 1
#                             gen.append(ex)
#                     else:
#                         print(f'{i}:\t{len(examples)}\texamples')
#                         # print(match)
#                         error += 1
#                 else:
#                     print(f'{i}:\t{len(matches)}\tmatches')
#                     error += 1
#     with open(gen_combine_output, 'w') as f:
#         json.dump(gen, f, indent=4)
#         print(f'gen: {len(gen)}')
#         print(f'error: {error}')
def parse_output():
    dirs = os.listdir(gen_output_root)
    gen = []
    count = 0
    error = 0
    for i in range(0, len(dirs)):
        # if i != 0:
        #     continue
        dir = os.path.join(gen_output_root, str(i))
        files = os.listdir(dir)
        for file in files:
            if not file.endswith('.c'):  # Skip files that are not .c files
                continue
            file_path = os.path.join(dir, file)
            with open(file_path, 'r') as f:
                try:
                    context = f.read()
                except UnicodeDecodeError as e:
                    print(f'{file_path}:\tUnicodeDecodeError, {e}')
                    continue
                matches = extract(context, 'text')
                if len(matches) == 5 or \
                        len(matches) == 6 or \
                        len(matches) == 7 or \
                        len(matches) == 8 or \
                        len(matches) == 9 or \
                        len(matches) == 10 or \
                        len(matches) == 19:
                    for num, match in enumerate(matches[-(len(matches) - 1):]):
                        file = str(i) + '_' + str(num) + '_1.c'
                        ex = {
                            'id': count,
                            'file_name': file,
                            'file_path': file_path,
                            'code': match,
                            'label': 1
                        }
                        count += 1
                        gen.append(ex)
                # elif len(matches) == 2 or len(matches) == 3:
                elif len(matches) == 1 or len(matches) == 2:
                    match = matches[-1]
                    # if 'int main() {' in match or \
                    #         'int main(int argc, char *argv[]) {' in match or \
                    #         'int main(int argc, char **argv) {' in match :
                    #     print(f'{i}:\tmain')
                    #     continue
                    examples = extract(match, 'example')
                    if len(examples) == 2 or len(examples) == 4 or len(examples) == 5 or len(examples) == 8 \
                            or len(examples) == 9 or len(examples) == 10 or len(examples) == 18:
                        for num, example in enumerate(examples):
                            file = str(i) + '_' + str(num) + '_1.c'
                            ex = {
                                'id': count,
                                'file_name': file,
                                'file_path': file_path,
                                'code': example,
                                'label': 1
                            }
                            count += 1
                            gen.append(ex)
                    else:
                        print(f'{i}:\t{len(examples)}\texamples')
                        # print(examples)
                        # print(match)
                        error += 1
                else:
                    print(f'{i}:\t{len(matches)}\tmatches')
                    error += 1
    with open(gen_combine_output, 'w') as f:
        json.dump(gen, f, indent=4)
        print(f'gen: {len(gen)}')
        print(f'error: {error}')

def remove_comments(code):
    pattern = r"(\".*?\"|\'.*?\')|(/\*.*?\*/|//[^\r\n]*$)"
    regex = re.compile(pattern, re.MULTILINE | re.DOTALL)

    def _replacer(match):
        if match.group(2) is not None:
            return ""  # so comments will be replaced by nothing
        else:  # returns the literal strings
            return match.group(1)

    return regex.sub(_replacer, code)



def remove_selected_structs(code):
    # Remove all #include statements
    code = re.sub(r'#include[^\n]*', '', code)
    code = re.sub(r'#define[^\n]*', '', code)

    # Remove typedef struct with {}
    code = re.sub(r'typedef\s+struct\s+\w*\s*\{[^}]*\}\s*\w+;', '', code, flags=re.DOTALL)
    code = re.sub(r'typedef\s+struct\s*\{[^}]*\}\s*\w+;', '', code, flags=re.DOTALL)
    code = re.sub(r'typedef\s+struct\s+\w*\s*\{[^}]*\}\s*\w+,\s*\*?\w+;', '', code, flags=re.DOTALL)

    code = re.sub(r'typedef\s+enum\s*\{([^\}]*)\}\s*(\w+);', '', code, flags=re.DOTALL)
    return code

def rm_comments():
    with open(gen_combine_output, 'r') as f:
        data = json.load(f)
    for item in data:
        item['code'] = remove_comments(item['code'])
        item['code'] = remove_selected_structs(item['code'])
    with open(rm_comments_output, 'w') as f:
        json.dump(data, f, indent=4)


def rm_():
    with open('/my_method/output_data_reveal_turbo/chain_reveal_4_2_result/mygen_bigvul.json', 'r') as f:
        data = json.load(f)
    for item in data:
        item['code'] = remove_comments(item['code'])
        item['code'] = remove_selected_structs(item['code'])
    with open('/my_method/output_data_reveal_turbo/chain_reveal_4_2_result/mygen_bigvul_after.json', 'w') as f:
        json.dump(data, f, indent=4)


def parse(root):
    dirs = os.listdir(root)
    preds = []
    targets = []
    count = 0
    error = 0
    for i in range(0, len(dirs)):
        # if i != 0:
        #     continue
        dir = os.path.join(root, str(i))
        files = os.listdir(dir)
        for file in files:
            if not file.endswith('.c'):  # Skip files that are not .c files
                continue
            if file.endswith('_1.c'):
                target = 1
                targets.append(target)
            elif file.endswith('_0.c'):
                target = 0
                targets.append(target)
            file_path = os.path.join(dir, file)
            with open(file_path, 'r') as f:
                try:
                    context = f.read()
                except UnicodeDecodeError as e:
                    print(f'{file_path}:\tUnicodeDecodeError, {e}')
                    continue
                context = context[-500:]
                # print(context)
                if "AI: Y" in context or "AI: y" in context:
                    pred = 1
                    preds.append(pred)
                elif "AI: N" in context or "AI: n" in context:
                    pred = 0
                    preds.append(pred)
                else:
                    print(f'{file_path}:\tAI not found')
    print(f'preds: {len(preds)}')
    print(f'targets: {len(targets)}')
    print(f'preds: {preds}')
    print(f'targets: {targets}')
    print(f'f1_score: {f1_score(targets, preds)}')
    return preds, targets
    # with open(gen_combine_output, 'w') as f:
    #     json.dump(gen, f, indent=4)
    #     print(f'gen: {len(gen)}')
    #     print(f'error: {error}')

def parse_all():
    dirs = glob.glob(gen_output_root + '*')
    # dirs = glob.glob('/Users/mymac/PycharmProjects/pythonProject/my_method/1/gpt_reveal_cot' + '*')
    preds = []
    targets = []
    for dir in dirs:
        p, t = parse(dir)
        preds += p
        targets += t
    print(f'preds: {len(preds)}')
    print(f'targets: {len(targets)}')
    print(f'preds: {preds}')
    print(f'targets: {targets}')
    print(f'f1_score: {f1_score(targets, preds)}')

def x():
    dataset = 'bigvul'
    root = '/Users/mymac/PycharmProjects/pythonProject/my_method/output_data_' + dataset
    path = os.path.join(root, 'prediction*')
    # Use glob to get all directories that match the pattern
    directories = [f for f in glob.glob(path) if os.path.isdir(f)]
    count = 0
    gen = []
    for dirs in directories:
        for i in range(0, len(dirs)):
            dir = os.path.join(dirs, str(i))
            if not os.path.exists(dir):
                continue
            files = os.listdir(dir)
            for file in files:
                if not file.endswith('.c'):  # Skip files that are not .c files
                    continue
                file_path = os.path.join(dir, file)
                with open(file_path, 'r') as f:
                    try:
                        context = f.read()
                    except UnicodeDecodeError as e:
                        print(f'{file_path}:\tUnicodeDecodeError, {e}')
                        continue
                    matches = extract(context, 'text')
                    match = matches[0]
                    ex = {
                        'id': count,
                        'file_name': file,
                        'file_path': file_path,
                        'code': match,
                        'label': 1
                    }
                    count += 1
                    gen.append(ex)
    output = '/Users/mymac/PycharmProjects/pythonProject/my_method/1/' + dataset + '.json'
    with open(output, 'w') as f:
        json.dump(gen, f, indent=4)
        print(f'gen: {len(gen)}')


def select():
    dataset = 'bigvul'
    origin = '/Users/mymac/PycharmProjects/pythonProject/my_method/origin_data_' + dataset + '/' + dataset + '.json'
    sample = '/Users/mymac/PycharmProjects/pythonProject/my_method/1/' + dataset + '.json'
    output = '/Users/mymac/PycharmProjects/pythonProject/my_method/1/' + dataset + '_left.json'
    with open(origin, 'r') as f:
        origin = json.load(f)
    with open(sample, 'r') as f:
        sample = json.load(f)
    sample_name = set(item['file_name'] for item in sample)
    left = [item for item in origin if item['file_name'] not in sample_name]
    with open(output, 'w') as f:
        json.dump(left, f, indent=4)
        print(f'left: {len(left)}')


if __name__ == "__main__":
    # if not os.path.exists(gen_output_result_root):
    #     os.mkdir(gen_output_result_root)
    # parse_output()
    # rm_comments()

    # x()
    # select()

    # parse()
    parse_all()

    # rm_()

