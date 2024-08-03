#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_INPUT 256

void store_user_input(const char *input) {
    char *input_buffer;
    size_t input_length = strlen(input);

    // Vulnerability: Buffer may be too small for input plus null terminator
    input_buffer = malloc(MAX(MAX_USER_INPUT, input_length + 1));

    // Possible buffer overflow if input_length exceeds MAX_USER_INPUT
    strcpy(input_buffer, input);

    // Store input somewhere...

    free(input_buffer);
}

int main() {
    char user_input[1024];
    printf("Enter input: ");
    fgets(user_input, sizeof(user_input), stdin);
    store_user_input(user_input);
    return 0;
}