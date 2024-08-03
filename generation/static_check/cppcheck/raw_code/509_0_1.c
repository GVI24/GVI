void vulnerable_log(FILE *log_file, const char *message, ...) {
    va_list args;
    va_start(args, message);
    if (log_file != NULL) {
        fprintf(log_file, message, args); // Vulnerable usage
    }
    va_end(args);
}

