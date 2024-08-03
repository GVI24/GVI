void process_commands(const char *input_stream, char **commands) {
    int cmd_count = 0;
    const char *start = input_stream;
    const char *end;
    while ((end = strchr(start, ';')) != NULL) {
        ptrdiff_t cmd_length = end - start;
        if (cmd_length > 0) {
            commands[cmd_count] = (char *)malloc(cmd_length + 1); // Allocating memory for command
            strncpy(commands[cmd_count], start, cmd_length); // Copying command
            commands[cmd_count][cmd_length] = '\0';  // Null-terminating string
            cmd_count++;  // Vulnerable: No bounds check before increment
        }
        start = end + 1;
    }
}