void unsafe_sprintf(char *buffer, const char *format, char *user_input) {
    sprintf(buffer, format, user_input); // No bounds checking for buffer or user_input
}

