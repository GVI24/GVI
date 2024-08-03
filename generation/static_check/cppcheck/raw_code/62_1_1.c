#include <stdio.h>
#include <stdarg.h>

void log_message(const char *fmt, ...) {
    char log_buffer[1024];
    va_list args;
    va_start(args, fmt);
    // Vulnerability: Format string vulnerability if 'fmt' contains format specifiers controlled by an attacker
    vsprintf(log_buffer, fmt, args);
    va_end(args);
    // Log writing logic...
    printf("Log: %s\n", log_buffer);
}

// Example usage:
// log_message(user_controlled_input);