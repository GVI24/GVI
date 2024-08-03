void add_log_entry(char *log_buffer, size_t buffer_size, const char *entry) {
    size_t current_length = strlen(log_buffer);
    // Unsafe use of strcat, can cause buffer overflow if entry is too large
    if (current_length + strlen(entry) < buffer_size) {
        strcat(log_buffer, entry); // No bounds checking
    }
}