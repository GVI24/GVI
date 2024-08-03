int recv_network_message(int socket_fd, char *message_buf, size_t buf_len) {
    int msg_length;

    // Receive the length of the message
    read(socket_fd, &msg_length, sizeof(msg_length)); 

    // No check for msg_length against buf_len, can cause buffer overflow
    read(socket_fd, message_buf, msg_length); 

    // No validation or sanitation of message contents
    // ... Process message ...

    return 0;
}

