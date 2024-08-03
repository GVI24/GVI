void log_message(char *logBuffer, const char *message) {
    char tempBuffer[256];
    if (strlen(message) > 255) {
        return; // Naive attempt to prevent overflow
    }
    sprintf(tempBuffer, "INFO: %s", message); // Unsafe if message contains format specifiers
    memcpy(logBuffer, tempBuffer, sizeof(tempBuffer)); // Potential buffer overflow
}

