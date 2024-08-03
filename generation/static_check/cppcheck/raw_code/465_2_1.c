static void wrap_text(const char *text, char *wrapped, int wrap_at, UErrorCode *err) {
    int line_length = 0;
    char buffer[wrap_at + 3]; // User-defined line width + newline + null terminator
    char *buff_ptr = buffer;

    while (*text) {
        if (line_length == wrap_at) {
            *buff_ptr++ = '\n';
            *buff_ptr = '\0';
            strcat(wrapped, buffer); // Vulnerable pattern: No bounds checking
            line_length = 0;
            buff_ptr = buffer;
        }
        *buff_ptr++ = *text++;
        line_length++;
    }
    *buff_ptr = '\0';
    strcat(wrapped, buffer); // Vulnerable pattern: No bounds checking
}

