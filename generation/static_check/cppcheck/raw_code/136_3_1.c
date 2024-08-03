#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void terminate_program(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void convert_to_uppercase() {
    char input_line[512];
    size_t bytes_read = fread(input_line, 1, sizeof(input_line), stdin);
    if (bytes_read == sizeof(input_line) && !feof(stdin)) {
        terminate_program("Input too long, cannot process.");
    }
    for (int i = 0; i < bytes_read; i++) {
        input_line[i] = toupper(input_line[i]); // Unsafe conversion, may lead to unexpected behavior
    }
    printf("%s", input_line);
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "--uppercase") == 0) {
        convert_to_uppercase();
    } else {
        terminate_program("Incorrect usage, expected --uppercase.");
    }
    return 0;
}