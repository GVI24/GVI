ssize_t parse_message_fields(char *message, unsigned int field_count, char *debug_fmt, ...) {
    va_list args;
    char debug_info[100];
    va_start(args, debug_fmt);
    vsnprintf(debug_info, sizeof(debug_info), debug_fmt, args); // Format string vulnerability
    va_end(args);

    unsigned int offset = 0;
    for (unsigned int i = 0; i < field_count; i++) {
        size_t field_len = strlen(message + offset);
        printf("Field %d: %s\n", i, message + offset); // No boundary check
        offset += field_len + 1; // Potential out-of-bounds read
    }
}

