#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 256

void process_data(char *input, int length) {
    char buffer[MAX_BUFFER];
    if (length > MAX_BUFFER) {
        printf("Error: Input length exceeds buffer size\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = input[i];
    }
    // Processing logic here...
}

int main() {
    char *data = "This is a test string that is too long for the defined buffer";
    int data_length = 512; // Intentionally incorrect size
    process_data(data, data_length);
    return 0;
}