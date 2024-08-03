void process_user_input(char *user_input, size_t input_length) {
    char command_buffer[256];

    // Potential buffer overflow vulnerability
    memcpy(command_buffer, user_input, input_length);

    execute_command(command_buffer);
}

void execute_command(const char *command) {
    // Command execution logic...
}