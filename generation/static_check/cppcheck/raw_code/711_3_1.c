#define LOG_SIZE 256

typedef struct {
    int error_code;
    char error_log[LOG_SIZE];
} ErrorHandler;

void log_error(ErrorHandler *handler, const char *message) {
    if (handler->error_code == 0) {
        // Improper check for buffer size can lead to buffer overflow
        snprintf(handler->error_log, LOG_SIZE, "Error: %s", message);
    } else {
        printf("The error has already been logged.\n");
    }
}

void handle_network_packet(ErrorHandler *handler, char *packet) {
    if (validate_packet(packet) != 0) {
        // A negative or too large return value can lead to buffer overflow
        log_error(handler, packet); // Unsafe: packet contents may exceed LOG_SIZE
    }
    // ... process the packet
}