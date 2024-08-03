int init_network_connection() {
    int socket_fd = -1;
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Could not create socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        // Missing close(socket_fd);
        return -1;
    }

    // Rest of the setup code...

    if (setup_fail_condition) {
        // Cleanup missing here
        return -1;
    }

    return socket_fd;
}