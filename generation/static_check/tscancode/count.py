def count_unique_files(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        unique_files = set()
        for line in lines:
            file_name = line.split(":")[0]
            unique_files.add(file_name)
        return len(unique_files)

print(count_unique_files('/root/devign/data/static_check/TscanCode/TscanCode-master/release/linux/TscanCodeV2.14.2395.linux/err.txt'))