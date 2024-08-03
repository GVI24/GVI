static void custom_log(const char *user_format, ...) {
    va_list args;
    char log_buffer[512];
    va_start(args, user_format);
    // Vulnerable to format string exploit if user_format is controlled by user
    vsnprintf(log_buffer, sizeof(log_buffer), user_format, args);
    va_end(args);
    printf("%s", log_buffer); // Log the message
    // ... Further log processing ...
}

