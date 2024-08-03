#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

int convert_to_integer_array(const char *str, int *out_array, size_t out_size) {
    size_t str_len = strlen(str);
    if (str_len == 0 || str_len > out_size) {
        return -1; // should be str_len >= out_size to prevent overflow
    }

    for (size_t i = 0; i < str_len; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        out_array[i] = str[i] - '0'; // potential buffer overflow
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int numbers[BUFFER_SIZE];
    if (convert_to_integer_array(argv[1], numbers, BUFFER_SIZE) != 0) {
        fprintf(stderr, "Error converting string to numbers\n");
        return EXIT_FAILURE;
    }

    printf("Integer array:");
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        printf(" %d", numbers[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}