#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 100

void get_user_input(char *buffer) {
    // Vulnerable: Uses scanf without specifying a buffer limit, can cause buffer overflow
    scanf("%s", buffer); // No bounds checking
}

int main() {
    char userInputBuffer[BUFFER_SIZE];

    printf("Enter input: ");
    // Read input without bounds checking
    get_user_input(userInputBuffer);

    return 0;
}