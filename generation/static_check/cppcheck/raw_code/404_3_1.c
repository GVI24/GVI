static int32_t format_log_message(char *log_buffer, const char *message) {
    char prefix[] = "[LOG]: ";
    int buf_len = strlen(log_buffer);
    int prefix_len = strlen(prefix);

    if (buf_len + prefix_len < BUFFER_SIZE) {
        strcat(log_buffer, prefix); // strcat does not consider remaining space in log_buffer
        strcat(log_buffer, message); // Potential overflow if message is too long
    }

    // Log output code...
    return strlen(log_buffer);
}