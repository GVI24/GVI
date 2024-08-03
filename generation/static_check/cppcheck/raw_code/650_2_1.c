void process_commands(const char *commands, int size) {
    const char *cmd_ptr = commands;
    const char *cmd_end = commands + size;
    char current_cmd[256];

    while (cmd_ptr < cmd_end) {
        if (*cmd_ptr == '\n' || *cmd_ptr == '\r') {
            cmd_ptr++;
            continue;
        }

        char *cmd_write = current_cmd;
        while (cmd_ptr < cmd_end && *cmd_ptr != '\n' && *cmd_ptr != '\r') {
            *cmd_write++ = *cmd_ptr++; // Potential buffer overflow if command is too long
        }

        execute_command(current_cmd); // Assume this function exists
    }
}

