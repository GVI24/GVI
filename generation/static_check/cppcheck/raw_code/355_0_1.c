void execute_command(char *input) {
    char command[256];
    // Vulnerability: no bounds checking
    sprintf(command, "ls -l %s", input);
    system(command); // Potential command injection if input is not sanitized
}

