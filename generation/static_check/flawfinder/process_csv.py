import csv

def count_unique_files(file_path):
    with open(file_path, 'r') as f:
        reader = csv.reader(f)
        next(reader)  # Skip the header
        unique_files = set(row[0] for row in reader)
    return len(unique_files)

file_path = 'err.csv'  # Replace with your file path
print(count_unique_files(file_path))