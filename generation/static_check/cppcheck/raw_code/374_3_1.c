#define MAX_BUFFER_SIZE 512

int log_message(char *log_buffer, const char *message) {
    if (log_buffer == NULL || message == NULL) {
        return -1;
    }
    // Using strncpy without checking input message size compared to buffer
    strncpy(log_buffer, message, MAX_BUFFER_SIZE);
    log_buffer[MAX_BUFFER_SIZE - 1] = '\0';
    return 0;
}