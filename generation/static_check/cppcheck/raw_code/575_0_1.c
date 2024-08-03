void execute_command(struct command *cmd) {
    char buffer[256];
    FILE *fp;
    char *command = cmd->command_str;
    if (!command) {
        fprintf(stderr, "Command string is empty\n");
        return;
    }

    if (!(fp = popen(command, "r"))) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // Vulnerability: not checking if buffer ends correctly
    }

    if (pclose(fp)) {
        fprintf(stderr, "Command execution failed\n");
        exit(1);
    }
}