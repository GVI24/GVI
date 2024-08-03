void log_message(const char *message) {
    size_t messageLen;
    char *logBuffer;

    messageLen = strlen(message); // Vulnerability pattern
    logBuffer = (char *)malloc(messageLen + 1); // Unbounded allocation
    if (logBuffer == NULL) {
        // Log error
        return; 
    }

    // Missing bounds check, potential buffer overflow
    sprintf(logBuffer, "Log: %s", message); 
    puts(logBuffer);
    free(logBuffer);
}