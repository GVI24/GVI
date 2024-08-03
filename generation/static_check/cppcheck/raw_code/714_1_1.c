void log_client_activity(int client_fd, short event_type, void *logger) {
    char client_input[256];
    int read_bytes;

    read_bytes = read(client_fd, client_input, sizeof(client_input)); // Reading into buffer without null termination
    if (read_bytes <= 0) {
        // Handle errors or disconnection
    } else {
        printf(logger, client_input); // Unsafe format string and potential non-null terminated input
    }
}