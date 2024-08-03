void log_message(const char * log_format, ...) {
    char log_buffer[512];
    va_list args;
    va_start(args, log_format);
    vsprintf(log_buffer, log_format, args); // No bounds checking
    va_end(args);
    // Simulated logging action
    fputs(log_buffer, stderr);
}

