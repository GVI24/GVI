#include <string.h>
#include <stdio.h>

#define BUF_SIZE 128

void copy_input(char *source) {
    char stack_buffer[BUF_SIZE];
    strcpy(stack_buffer, source); // No bounds checking
    printf("%s\n", stack_buffer);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        copy_input(argv[1]);
    }
    return 0;
}