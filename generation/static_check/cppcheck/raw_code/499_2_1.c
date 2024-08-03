#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void log_message(char *message) {
    char log_buffer[128];
    // Vulnerability: snprintf does not check the length of message,
    // leading to buffer overflow if message exceeds 128 bytes.
    snprintf(log_buffer, sizeof(log_buffer), "LOG: %s", message);
    printf("%s\n", log_buffer);
}