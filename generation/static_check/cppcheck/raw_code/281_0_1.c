void log_message(const char *format, ...) {
    va_list args;
    char buffer[256];
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    puts(buffer); // Potential vulnerability: buffer may not be null-terminated
    va_end(args);
}