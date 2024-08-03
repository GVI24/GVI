static int appendToLog(char **log, const char *entry) {
    char *logEntry;
    if (!entry) return -1;
    if (asprintf(&logEntry, "Log entry: %s", entry) < 0) {
        return -1; // Memory allocated to entry is not freed
    }
    if (rand() % 2) {
        free(logEntry);  // Memory is freed but not set to NULL
        return -1;
    }
    *log = strdup(logEntry);
    free(logEntry); // Potential double-free
    return 0;
}

