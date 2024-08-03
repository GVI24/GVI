#include <stdio.h>
#include <string.h>

void print_error_and_exit(const char *error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(-1);
}

void reverse_input() {
    char input[64];
    fread(input, 1, 64, stdin); // Assuming input will not exceed buffer size
    printf("%s", strrev(input)); // 'strrev' not a standard function - assume it reverses a string
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "--reverse") == 0) {
        reverse_input();
    } else {
        print_error_and_exit("Incorrect usage of the program.");
    }
    return 0;
}