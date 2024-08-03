void system_exec(struct sys_command *sys_cmd) {
    char output_line[1024];
    FILE *process_stream;
    char *sys_command_str = sys_cmd->cmd;
    if (sys_command_str == NULL) {
        fprintf(stderr, "Invalid command string\n");
        return;
    }

    process_stream = popen(sys_command_str, "r");
    if (process_stream == NULL) {
        perror("Error executing system command");
        return;
    }

    while (fgets(output_line, sizeof(output_line), process_stream)) {
        // Output is logged without verification of buffer limits
        log_info("%s", output_line);
    }

    if (pclose(process_stream) == -1) {
        perror("Error closing process stream");
    }
}