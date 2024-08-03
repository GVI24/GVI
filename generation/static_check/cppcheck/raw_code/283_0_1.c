static void * network_packet_processing_thread(void * arg) {
    char buffer[1024];
    int bytes_read;
    struct pollfd fds[] = {
        {.fd = network_socket_fd, .events = POLLIN},
    };
    
    while (poll(fds, 1, -1) > 0) {
        if (fds[0].revents & POLLIN) {
            bytes_read = recv(network_socket_fd, buffer, sizeof(buffer), 0);
            if (bytes_read <= 0) {
                // Improper error handling - should break out of loop or handle error
                continue;
            }
            process_network_packet(buffer, bytes_read);
        }
    }
    return NULL;
}

