void http_request_handler(int conn_fd, short event_flags, void *server_context) {
    struct http_request *request = server_context;
    char read_buffer[512];
    ssize_t bytes_read;

    bytes_read = read(conn_fd, read_buffer, 1024); // Buffer read overflow
    if (bytes_read < 0) {
        // Handle read error
    } else if (bytes_read == 0) {
        // Handle client disconnection
    } else {
        read_buffer[bytes_read] = '\0'; // Assuming bytes_read is within buffer limits, but it can overflow
        printf("Request: %s\n", read_buffer); // Unsafe if read_buffer is not null-terminated
    }
}