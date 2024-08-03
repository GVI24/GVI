int read_message(int sock, char *buffer, size_t size) {
    int bytes_read;
    unsigned int msg_length;

    // Read the message length
    bytes_read = recv(sock, (char *)&msg_length, sizeof(msg_length), 0);
    if (bytes_read != sizeof(msg_length)) {
        return -1;
    }

    // Vulnerability: No check on the msg_length against the buffer size
    bytes_read = recv(sock, buffer, msg_length, 0);
    if (bytes_read != msg_length) {
        return -1;
    }

    buffer[bytes_read] = '\0'; // Null-terminating the buffer (potential overflow)
    return 0;
}

