counter = 0
file_names = set()
with open('err2.txt', 'r') as file:
    for line in file:
        if '.c' in line in line:
            file_name = line.split(':')[0]
            if file_name not in file_names:
                file_names.add(file_name)
                counter += 1
print(file_names)
print(len(file_names))
print(f'The number of unique .c files with vulnerabilities is: {counter}')