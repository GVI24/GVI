#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_to_binary(char *input) {
    unsigned char binary[10]; // fixed-size buffer
    size_t input_len = strlen(input);

    if (input_len > sizeof(binary)) {
        fprintf(stderr, "Input too large!\n");
        return;
    }

    for (size_t i = 0; i < input_len; ++i) {
        binary[i] = (unsigned char)input[i]; // potential buffer overflow
    }
    
    printf("Binary data:");
    for (size_t i = 0; i < input_len; ++i) {
        printf(" %02X", binary[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    string_to_binary(argv[1]);
    return EXIT_SUCCESS;
}

