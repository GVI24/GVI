void logAction(const char *action, const char *filename) {
    char logEntry[256];
    sprintf(logEntry, "Action: %s, File: %s\n", action, filename);  // No bounds checking
    printf("%s", logEntry);
}

