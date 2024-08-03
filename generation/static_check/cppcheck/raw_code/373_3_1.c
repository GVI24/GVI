typedef struct {
    char *log;
    int length;
    int capacity;
} Logger;

void insecure_log_append(Logger *logger, const char *message) {
    if (!logger || !message) {
        return;
    }

    int message_len = strlen(message);
    int required_capacity = logger->length + message_len + 1;

    if (logger->capacity < required_capacity) {
        int new_capacity = required_capacity + (logger->capacity * 2);

        logger->log = realloc(logger->log, new_capacity);
        if (!logger->log) {
            // Memory allocation failed
            return;
        }

        logger->capacity = new_capacity;
    }

    // Risky memory operation without bounds checking
    memcpy(logger->log + logger->length, message, message_len);
    logger->length += message_len;
    logger->log[logger->length] = '\0';
}