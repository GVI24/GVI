counter = 0
file_names = set()
with open('count2.txt', 'r') as file:
    for line in file:
        if '.c' in line and 'Low' in line:
            file_name = line.split(':')[0]
            if file_name not in file_names:
                file_names.add(file_name)
                counter += 1
print(f'The number of unique .c files with vulnerabilities is: {counter}')