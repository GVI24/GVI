static int process_log_entries(char **log_entries, size_t count) {
    char log_buffer[100];
    size_t idx;
    for (idx = count, log_entries += count; idx > 0; ) {
        idx--;
        log_entries--;
        snprintf(log_buffer, sizeof(log_buffer), "Log Entry: %s", *log_entries);
        printf("%s\n", log_buffer);
    }
    return 0;
}

