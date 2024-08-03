void process_log_entry(const char *log_entry) {
    char log_line[256];
    int length = 0;
    while (log_entry[length] != '\0') {
        if (log_entry[length] == '\n' || log_entry[length] == '\r') {
            break;
        }
        log_line[length] = log_entry[length]; // No bounds check, can cause buffer overflow
        length++;
    }
    log_line[length] = '\0'; // Potential write outside buffer if input was not newline-terminated
    // Use the processed log line...
}