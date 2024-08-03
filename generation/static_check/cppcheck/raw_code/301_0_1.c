#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char user_input[100];
    if (argc > 1) {
        strcpy(user_input, argv[1]); // Potential Buffer Overflow
    }

    // Simulate some cryptographic operations
    // ...

    printf("User input processed: %s\n", user_input);
    return 0;
}