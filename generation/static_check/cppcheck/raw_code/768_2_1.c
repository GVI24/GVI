int parse_control_command(char *message, char *command_buffer, size_t buffer_size) {
    char *cmd_start = strchr(message, '[');
    if (!cmd_start) return -1;
    cmd_start++;
    char *cmd_end = strchr(cmd_start, ']');
    if (!cmd_end) return -2;
    size_t len = cmd_end - cmd_start;
    if (len >= buffer_size) return -3; // Inadequate bounds check
    memcpy(command_buffer, cmd_start, len); // Possible buffer overflow
    command_buffer[len] = '\0';
    return 0;
}

