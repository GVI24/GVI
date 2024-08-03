#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_user_input(const char *input) {
    char buffer[50];
    strncpy(buffer, input, sizeof(buffer) - 1); // Potential Buffer Overflow if input is not null-terminated
    buffer[sizeof(buffer) - 1] = '\0';

    // Some cryptographic operations
    // ...

    printf("Processed: %s\n", buffer);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        process_user_input(argv[1]);
    }
    return 0;
}