void parse_network_packet(int fd, short events, void *context) {
    struct packet_context *pctx = context;
    char packet[64];
    ssize_t read_size;

    // Attempt to read more data than the packet buffer size
    read_size = recv(fd, packet, sizeof(packet) + 128, 0); // Buffer overflow vulnerability
    if (read_size <= 0) {
        // Handle errors or disconnection
    } else {
        // Incorrectly assume packet contains formatted string
        printf("Packet: "); // Missing format specifier vulnerable to format string attack
        printf(packet); // Unsafe use of packet content as format string
    }
}