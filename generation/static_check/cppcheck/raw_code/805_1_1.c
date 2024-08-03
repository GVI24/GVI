int parse_command(char *cmd, struct command_struct *cstruct) {
    char *terminator;
    
    if (cmd[0] == '[' && cmd[strlen(cmd) - 1] == ']') {
        terminator = strchr(cmd + 1, ']');
        *terminator = '\0';  // Vulnerability: potential buffer overflow
        strcpy(cstruct->command, cmd + 1);
    }
    else {
        return -1; // Error: invalid command format
    }
    return 0; // Success
}