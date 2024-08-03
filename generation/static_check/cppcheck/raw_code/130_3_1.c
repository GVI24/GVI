void custom_evbuffer_add_printf(char *buffer, size_t buffer_size, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    // Improper use of vsprintf can lead to a buffer overflow
    vsprintf(buffer, fmt, args);
    va_end(args);
}

