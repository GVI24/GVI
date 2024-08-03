static void log_message(const char *user_input) {
    char log_buffer[256];
    // Vulnerability: user_input is directly used in a format function.
    sprintf(log_buffer, user_input);
    // Log output to a file or stderr (Not shown here for simplicity)
    fprintf(stderr, "%s", log_buffer);
}