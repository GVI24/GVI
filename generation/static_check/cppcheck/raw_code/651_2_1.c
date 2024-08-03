void handle_client_input(int client_socket) {
    char buffer[128]; // Fixed size buffer
    int received_length = recv(client_socket, buffer, sizeof(buffer) + 100, 0); // Overflows buffer
    if (received_length > 0) {
        buffer[received_length] = '\0'; // Potential buffer overflow
        printf("Client said: %s\n", buffer);
    }
}

