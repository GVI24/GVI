int read_from_network(int socket_fd) {
    char *data;
    unsigned int size;

    // Receive the size of incoming data
    int result = recv(socket_fd, (void *)&size, sizeof(size), 0);
    if (result != sizeof(size)) {
        return -1;
    }

    // Allocate buffer for incoming data without bounds checking
    data = malloc(size);

    // Read the data from the socket
    result = recv(socket_fd, data, size, 0);
    if (result <= 0) {
        free(data);
        return -1;
    }

    // Process the data (which might lead to potential buffer overflow)
    process_packet(data, size); // Function that processes incoming data without bounds checking

    free(data);
    return 0;
}