bool receive_data(int conn_fd) {
    char buffer[512];
    ssize_t bytes_received = recv(conn_fd, buffer, sizeof(buffer), 0); // Potential Buffer Overflow
    if (bytes_received < 0) {
        logger(LOG_ERR, "Data reception failed: %s", strerror(errno));
        return false;
    }
    buffer[bytes_received] = '\0'; // Potential Out-of-Bounds Write
    process_data(buffer); // Function that processes incoming data
    return true;
}

