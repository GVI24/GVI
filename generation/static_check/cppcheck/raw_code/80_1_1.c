int snprintf_wrapper(char *buf, size_t buf_size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int written = vsnprintf(buf, buf_size, format, args); // Vulnerable: No format string validation
    va_end(args);
    return written;
}