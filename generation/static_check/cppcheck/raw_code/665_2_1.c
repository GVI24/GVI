int log_message(log_t *log, const char *message) {
    if (!log || !message) {
        return -1;
    }

    log->message = strdup(message);
    if (!log->message) {
        return -1; // Memory leak if 'log->message' is not freed on error
    }

    // Log the message...

    return 0;
}

typedef struct {
    unsigned char *key_stream;
} stream_cipher_t;

