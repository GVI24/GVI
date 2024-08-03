#define LOG_MESSAGE_SIZE 256
typedef struct {
    char log_message[LOG_MESSAGE_SIZE];
} LoggingContext;

void log_message(LoggingContext *ctx, const char *message) {
    if (ctx == NULL || message == NULL) {
        return;
    }
    // Vulnerability: No bounds checking on the length of message
    strncpy(ctx->log_message, message, sizeof(ctx->log_message));
    ctx->log_message[LOG_MESSAGE_SIZE - 1] = '\0';
}

