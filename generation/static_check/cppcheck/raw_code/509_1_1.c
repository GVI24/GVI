void debug_message(const char *format, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args); // Vulnerable usage
    printf("DEBUG: %s\n", buffer);
    va_end(args);
}

