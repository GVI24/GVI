void print_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args); // Vulnerable: No format string validation
    va_end(args);
    fprintf(stderr, "\n");
}