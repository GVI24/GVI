#include <stdio.h>

#define BUFFER_SIZE 256

void readMessage(char *message) {
    // Vulnerable: Reading into a fixed-size buffer without checking the size of input
    char buffer[BUFFER_SIZE];
    scanf("%s", buffer); // Unsafe: can cause buffer overflow if input exceeds BUFFER_SIZE
    strcpy(message, buffer);
}

int main() {
    char message[256];
    printf("Enter a message: ");
    readMessage(message);
    return 0;
}