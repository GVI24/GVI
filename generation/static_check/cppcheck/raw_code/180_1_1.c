void log_activity(const char *activity, const char *user) {
    char log_entry[100];
    int index = 0;
    while (*activity) {
        log_entry[index++] = *activity++;
    }
    log_entry[index++] = ' ';
    log_entry[index++] = '|';
    log_entry[index++] = ' ';
    while (*user) {
        log_entry[index++] = *user++;
    }
    log_entry[index] = '\0';
    // Log the activity
    // ...
}