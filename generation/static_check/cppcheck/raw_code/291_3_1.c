static void append_formatted_data(char **buffer, size_t *currlen, size_t *maxlen, const char *format, ...) {
    va_list args;
    va_start(args, format);
    while (*format) {
        if (*currlen == *maxlen) {
            *maxlen += 1024;
            char *new_buffer = realloc(*buffer, *maxlen);
            if (!new_buffer) {
                // Not handling realloc failure correctly
                va_end(args);
                return;
            }
            *buffer = new_buffer;
        }
        if (*format == '%') {
            // Simplified formatting logic for example purposes
            format++;
            if (*format == 'c') {
                char c = (char)va_arg(args, int);
                (*buffer)[(*currlen)++] = c; // Potential buffer overflow
            }
            // Could add more format specifiers handling here
        } else {
            (*buffer)[(*currlen)++] = *format; // Potential buffer overflow
        }
        format++;
    }
    va_end(args);
}