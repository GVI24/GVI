#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100

void copy_user_input(const char *input) {
    char buffer[INPUT_SIZE];
    strcpy(buffer, input); // No bounds checking, could overflow if input is longer than INPUT_SIZE
    printf("User input: %s\n", buffer);
}