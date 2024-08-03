#include <stdio.h>
#include <stdlib.h>

int calculate_length(const char *str) {
    return strlen(str); // potential null pointer dereference if str is NULL
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int length = calculate_length(argv[1]);
    printf("Length of string: %d\n", length);
    return EXIT_SUCCESS;
}

