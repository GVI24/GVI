void log_message(const char *user_input) {
    char log_buffer[256];
    // Vulnerability: 'user_input' could contain format specifiers that could lead to memory corruption
    sprintf(log_buffer, user_input);
    printf("%s\n", log_buffer);
    // ... logging logic...
}