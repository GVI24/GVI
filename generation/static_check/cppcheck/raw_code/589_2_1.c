#include <stdlib.h>
#include <stdio.h>

void execute_command(char *user_input) {
    char command[256];
    snprintf(command, sizeof(command), "echo %s", user_input); // Vulnerable to command injection
    system(command); // Unsafe: user input passed to system call
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        execute_command(argv[1]);
    }
    return 0;
}