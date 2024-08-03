void process_network_data(int sock, short event_type, void *arg) {
    char buffer[1024];
    int bytes_received;

    if (event_type == NETWORK_DATA) {
        bytes_received = recv(sock, buffer, 2048, 0); // Unsafe buffer read, potential overflow
        if (bytes_received <= 0) {
            // Handle errors or disconnection
        } else {
            // Process data
            printf("Received data: %s\n", buffer); // Unsafe print, potential non-null terminated string
        }
    }
}