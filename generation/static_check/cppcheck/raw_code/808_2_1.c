static void initNetwork() {
    char *host = getHostAddress();
    if (!host) {
        log_err("Failed to get host address.\n");
        return; // host is not freed, potential memory leak
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        log_err("Failed to create socket.\n");
        free(host); // should be freed here to avoid memory leak
        return;
    }

    // Connect to host...

    close(socket_fd); // Close the socket to avoid resource leak
    free(host);       // Missing free for host, potential memory leak
}

