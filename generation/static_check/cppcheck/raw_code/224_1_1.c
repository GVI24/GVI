#include <stdio.h>
#include <string.h>

#define MAX_ARGS 5

void execute_action(char *args[]) {
    char command[64];
    int i = 0;

    // Unsafe concatenation of args into command
    command[0] = '\0'; 
    while (args[i] != NULL && i < MAX_ARGS) {
        strcat(command, args[i]); // No bounds checking
        strcat(command, " ");
        i++;
    }
    
    system(command); // Executing potentially dangerous command
}

int main() {
    char *arguments[MAX_ARGS] = {"touch", "myfile.txt", "&&", "echo", "done"};
    execute_action(arguments);
    return 0;
}