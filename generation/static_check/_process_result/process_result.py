import xml.etree.ElementTree as ET
import pandas as pd

def parse_cppcheck(xml_file):
    result = []
    # 解析XML文件
    tree = ET.parse(xml_file)
    root = tree.getroot()

    # 遍历每个错误
    for error in root.iter('error'):
        # 获取错误的所有属性
        id = error.get('id')
        severity = error.get('severity')
        msg = error.get('msg')
        verbose = error.get('verbose')
        cwe = error.get('cwe')

        location = error.find('location')
        if location is not None:
            file = location.get('file')
            line = location.get('line')
        else:
            # print("未找到location元素")
            continue

        # print(f"ID：{id}, 严重性：{severity}, 信息：{msg}, 详细：{verbose}, "
        #       f"CWE：{cwe}, 文件：{file}, 行号：{line}")
        info = {
            'id': id,
            'severity': severity,
            'msg': msg,
            'verbose': verbose,
            'cwe': cwe,
            'file': file,
            'line': line
        }
        result.append(info)
    return result


def parse_flawfinder(csv_file):
    result = []
    # 读取CSV文件
    df = pd.read_csv(csv_file)

    # 遍历每一行
    for index, row in df.iterrows():
        # 获取错误的所有属性
        file = row['File']
        line = row['Line']
        column = row['Column']
        default_level = row['DefaultLevel']
        level = row['Level']
        category = row['Category']
        name = row['Name']
        warning = row['Warning']
        suggestion = row['Suggestion']
        note = row['Note']
        cwes = row['CWEs']
        context = row['Context']
        fingerprint = row['Fingerprint']
        tool_version = row['ToolVersion']
        rule_id = row['RuleId']
        help_uri = row['HelpUri']

        # print(f"文件：{file}, 行号：{line}, 列：{column}, "
        #       f"默认等级：{default_level}, 等级：{level}, 类别：{category}, "
        #       f"名称：{name}, 警告：{warning}, 建议：{suggestion}, 注释：{note}, "
        #       f"CWEs：{cwes}, 上下文：{context}, 指纹：{fingerprint}, "
        #       f"工具版本：{tool_version}, 规则ID：{rule_id}, 帮助URI：{help_uri}")
        info = {
            'file': file,
            'line': line,
            'column': column,
            'default_level': default_level,
            'level': level,
            'category': category,
            'name': name,
            'warning': warning,
            'suggestion': suggestion,
            'note': note,
            'cwes': cwes,
            'context': context,
            'fingerprint': fingerprint,
            'tool_version': tool_version,
            'rule_id': rule_id,
            'help_uri': help_uri
        }
        result.append(info)
    return result


def parse_rats(xml_file):
    result = []
    # 解析XML文件
    tree = ET.parse(xml_file)
    root = tree.getroot()

    # 遍历每个漏洞
    for vulnerability in root.iter('vulnerability'):
        # 获取漏洞的属性
        severity = vulnerability.find('severity').text
        message = vulnerability.find('message').text.strip()

        if vulnerability.find('type') is not None:
            type = vulnerability.find('type').text
        else:
            type = None

        # 遍历每个文件
        for file in vulnerability.iter('file'):
            file_name = file.find('name').text
            line = file.find('line').text

            # print(f"严重性：{severity}, 类型：{type}, 信息：{message}, "
            #       f"文件：{file_name}, 行号：{line}")
            info = {
                'severity': severity,
                'type': type,
                'message': message,
                'file': file_name,
                'line': line
            }
            result.append(info)
    return result

def parse_tscancode(xml_file):
    result = []
    # 解析XML文件
    tree = ET.parse(xml_file)
    root = tree.getroot()

    # 遍历每个漏洞
    for vulnerability in root.iter('error'):
        # 获取漏洞的属性
        file = vulnerability.get('file')
        line = vulnerability.get('line')
        id = vulnerability.get('id')
        subid = vulnerability.get('subid')
        severity = vulnerability.get('severity')
        msg = vulnerability.get('msg')
        func_info = vulnerability.get('func_info')
        content = vulnerability.get('content')

        # print(f"文件：{file}, 行号：{line}, ID：{id}, 子ID：{subid}, "
        #       f"严重性：{severity}, 信息：{msg}, 函数信息：{func_info}, "
        #       f"内容：{content}")
        info = {
            'file': file,
            'line': line,
            'id': id,
            'subid': subid,
            'severity': severity,
            'msg': msg,
            'func_info': func_info,
            'content': content
        }
        result.append(info)
    return result

def mapping(results, tool):
    mapping_level = {
        'cppcheck':
            {'information': 0, 'style': 1, 'performance': 1, 'portability': 1, 'warning': 2, 'error': 3},
        'flawfinder':
            {0: 1, 1: 1, 2: 2, 3: 2, 4: 3, 5: 3},
        'rats':
            {'Low': 1, 'Medium': 2, 'High': 3},
        'tscancode':
            {'Information': 1, 'Warning': 2, 'Serious': 3, 'Critical': 3}
    }

    for result in results:
        if tool == 'flawfinder':
            severity = result['level']
        else:
            severity = result['severity']

        tool_mapping = mapping_level.get(tool)

        map_level = tool_mapping.get(severity)
        result['map_level'] = map_level
        result['tool'] = tool
        result['file'] = result['file'].split('/')[-1]


    return results


def count_votes(results, min_level, min_tool):
    # 初始化等级结果字典
    level_counts = {}

    # 遍历每个结果
    for result in results:
        # 获取文件名和行号
        file = result['file']
        line = result['line']
        tool = result['tool']

        # 如果这个文件还没有在等级结果中，就添加它
        if file not in level_counts:
            level_counts[file] = {
                'lines': {},
                'max_levels': {'cppcheck': None, 'flawfinder': None, 'rats': None, 'tscancode': None},
                'total_lines': 0,
                'consistent_lines': 0,
                'inconsistent_lines': 0
            }

        # 如果这个行号还没有在文件的字典中，就添加它
        if line not in level_counts[file]['lines']:
            level_counts[file]['lines'][line] = {'cppcheck': None, 'flawfinder': None, 'rats': None, 'tscancode': None}

        # 获取等级
        level = result['map_level']

        # 如果等级在min_level以上，记录每个工具的等级
        if level >= min_level:
            level_counts[file]['lines'][line][tool] = level

            # 更新文件级别的最大等级
            if level_counts[file]['max_levels'][tool] is None or level > level_counts[file]['max_levels'][tool]:
                level_counts[file]['max_levels'][tool] = level

            # 更新总行数和一致/不一致行数
            level_counts[file]['total_lines'] += 1
            if sum(level is not None for level in level_counts[file]['lines'][line].values()) >= min_tool:
                level_counts[file]['consistent_lines'] += 1
            else:
                level_counts[file]['inconsistent_lines'] += 1

    return level_counts


def count_files(level_counts):
    # 初始化文件统计字典
    file_counts = {'1_tools': 0, '2_tools': 0, '3_tools': 0, '4_tools': 0}

    # 遍历每个文件
    for file, data in level_counts.items():
        # 计算有多少个工具判定该文件存在等级在min_level以上的漏洞
        tool_count = sum(1 for tool, level in data['max_levels'].items() if level is not None)

        # 更新文件统计字典
        if tool_count > 0:
            file_counts[f'{tool_count}_tools'] += 1

    return file_counts


def count_lines(level_counts):
    # 初始化行统计字典
    line_counts = {'1_tools': 0, '2_tools': 0, '3_tools': 0, '4_tools': 0}

    # 遍历每个文件的每一行
    for file, data in level_counts.items():
        for line, tools in data['lines'].items():
            # 计算有多少个工具判定该行存在漏洞
            tool_count = sum(1 for tool, level in tools.items() if level is not None)

            # 更新行统计字典
            if tool_count > 0:
                line_counts[f'{tool_count}_tools'] += 1

    return line_counts


def count_consistent_files(level_counts):
    # 初始化一致文件计数
    consistent_files = 0

    # 遍历每个文件
    for file, data in level_counts.items():
        # 如果存在一致的漏洞行，增加一致文件计数
        if data['consistent_lines'] > 0:
            consistent_files += 1

    return consistent_files




if __name__ == '__main__':

    # 调用函数解析Cppcheck的XML报告
    cppcheck = parse_cppcheck('/root/reveal/static_check/_process_result/result_data/cppcheck.xml')
    # 调用函数解析Flawfinder的CSV报告
    flawfinder = parse_flawfinder('/root/reveal/static_check/_process_result/result_data/flawfinder.csv')
    # 调用函数解析RATS的XML报告
    rats = parse_rats('/root/reveal/static_check/_process_result/result_data/rats.xml')
    # 调用函数解析TscanCode的XML报告
    tscancode = parse_tscancode('/root/reveal/static_check/_process_result/result_data/tscancode.xml')

    # # 调用函数解析Cppcheck的XML报告
    # cppcheck = parse_cppcheck('/root/devign/data/static_check/_process_result/result_data/cppcheck.xml')
    # # 调用函数解析Flawfinder的CSV报告
    # flawfinder = parse_flawfinder('/root/devign/data/static_check/_process_result/result_data/flawfinder.csv')
    # # 调用函数解析RATS的XML报告
    # rats = parse_rats('/root/devign/data/static_check/_process_result/result_data/rats.xml')
    # # 调用函数解析TscanCode的XML报告
    # tscancode = parse_tscancode('/root/devign/data/static_check/_process_result/result_data/tscancode.xml')

    # print(f"Cppcheck报告中的漏洞数量：{len(cppcheck)}")
    # print(f"Flawfinder报告中的漏洞数量：{len(flawfinder)}")
    # print(f"RATS报告中的漏洞数量：{len(rats)}")
    # print(f"TscanCode报告中的漏洞数量：{len(tscancode)}")

    cppcheck = mapping(cppcheck, 'cppcheck')
    flawfinder = mapping(flawfinder, 'flawfinder')
    rats = mapping(rats, 'rats')
    tscancode = mapping(tscancode, 'tscancode')

    # 将所有工具的结果合并到一个列表中
    all_results = cppcheck + flawfinder + rats + tscancode

    # 使用count_votes函数统计总体投票结果
    vote_counts = count_votes(all_results, min_level=3, min_tool=4)

    import pprint
    pp = pprint.PrettyPrinter(indent=4)
    # pp.pprint(vote_counts)


    file_counts = count_files(vote_counts)
    pp.pprint(file_counts)

    line_counts = count_lines(vote_counts)
    pp.pprint(line_counts)

    consistent_files = count_consistent_files(vote_counts)
    pp.pprint(consistent_files)







