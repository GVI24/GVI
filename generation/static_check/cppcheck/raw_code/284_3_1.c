#include <stdio.h>

#define STATIC_BUF_SIZE 100

void process_input(char *user_input) {
    char static_buffer[STATIC_BUF_SIZE];
    int user_input_len = strlen(user_input);
    if (user_input_len >= STATIC_BUF_SIZE) {
        fprintf(stderr, "Error: Input exceeds static buffer size\n");
        exit(1);
    }
    for (int i = 0; i < user_input_len; i++) {
        static_buffer[i] = user_input[i]; // Potential buffer overflow
    }
    // Perform further processing on static_buffer...
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        process_input(argv[1]);
    }
    return 0;
}