#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH 1024

void modify_path(int f, const char *base_dir) {
    char file_path[MAX_PATH];
    int length;

    // Vulnerable to buffer overflow if concatenated strings exceed MAX_PATH
    length = read(f, file_path, MAX_PATH); // Assume read is a safe function like read(2) but used incorrectly here
    if (length > 0) {
        strcat(file_path, base_dir); // Unsafe strcat without bounds checking
        strcat(file_path, "/newfile.txt");
        printf("Modified path: %s\n", file_path);
    } else {
        perror("Failed to read path");
        exit(EXIT_FAILURE);
    }
}