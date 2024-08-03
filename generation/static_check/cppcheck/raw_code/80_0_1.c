void log_message(FILE *log_file, const char *format, ...) {
    va_list args;
    va_start(args, format);
    if(log_file) {
        vfprintf(log_file, format, args); // Vulnerable: No format string validation
    }
    va_end(args);
}