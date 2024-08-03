void run_external(struct ext_command *external) {
    char read_buffer[4096];
    FILE *cmd_output;
    char *ext_cmd = external->extern_cmd;
    if (ext_cmd == NULL) {
        fprintf(stderr, "Error: command is NULL\n");
        exit(EXIT_FAILURE);
    }

    cmd_output = popen(ext_cmd, "r");
    if (!cmd_output) {
        perror("Could not execute external command");
        exit(EXIT_FAILURE);
    }

    while (fgets(read_buffer, sizeof(read_buffer), cmd_output) != NULL) {
        // Vulnerable usage of buffer without checking for overflows or correct termination
        fputs(read_buffer, stdout);
    }

    if (pclose(cmd_output)) {
        fprintf(stderr, "Failed to close command stream\n");
        exit(EXIT_FAILURE);
    }
}