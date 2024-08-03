void log_message(char *user_input) {
    char log_buffer[256];
    sprintf(log_buffer, user_input); // Uncontrolled format string vulnerability.
    printf("LOG: %s\n", log_buffer);
    // ... (rest of the logging code)
}

