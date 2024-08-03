static int network_packet_read(struct connection *conn, const void **buf, size_t *bsz) {
    size_t packet_size = conn->packet_size;
    char *packet_buf;
    ssize_t bytes_received;

    packet_buf = (char *)malloc(packet_size);
    bytes_received = recv(conn->socket, packet_buf, packet_size, 0);

    if (bytes_received < 0) {
        free(packet_buf);
        *bsz = 0;
        return -1;
    } else if (bytes_received == 0) {
        free(packet_buf);
        *buf = NULL;
        *bsz = 0;
        return 0; // Connection closed
    } else if ((size_t)bytes_received > packet_size) {
        // Buffer over-read vulnerability
        bytes_received = packet_size;
    }

    *bsz = bytes_received;
    *buf = packet_buf;
    return 1;
}

