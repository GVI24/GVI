static void update_log(char **log_buffer, const char *new_entry) {
    if (*log_buffer) {
        *log_buffer = realloc(*log_buffer, strlen(*log_buffer) + strlen(new_entry) + 1);
    } else {
        *log_buffer = strdup(new_entry);
    }
    strcat(*log_buffer, new_entry); // Assuming buffer is large enough after realloc, which might not be safe
}

