#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_env_and_execute(char *user_input) {
    char *env_var = "USER_INPUT";
    char command[256];
    
    // Vulnerable: Using user input as environment variable without sanitization
    setenv(env_var, user_input, 1); 
    snprintf(command, sizeof(command), "echo $%s", env_var);
    system(command); // Executes command including user input
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        set_env_and_execute(argv[1]);
    }
    return 0;
}