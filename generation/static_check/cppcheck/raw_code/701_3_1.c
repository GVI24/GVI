#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_shell_command(char *cmd, char **args, size_t num_args) {
    char **command = malloc((num_args + 2) * sizeof(char *));
    size_t i;

    command[0] = "/bin/sh";
    command[1] = "-c";
    for (i = 0; i < num_args; i++) {
        command[i + 2] = args[i]; // No bounds checking
    }
    command[num_args + 2] = NULL; // This could write beyond allocated memory

    execv(command[0], command);
    perror("execv");
    free(command);
}

// Usage example
// int main() {
//     char *args[] = { "echo 'Hello World!'", NULL };
//     execute_shell_command("echo", args, 1);
//     return 0;
// }