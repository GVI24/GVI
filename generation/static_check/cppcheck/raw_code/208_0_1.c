static int dtls_process_packet(SSL *ssl, unsigned char *packet, unsigned int packet_len) {
    if (packet_len > ssl->d1->mtu) {
        return -1; // Packet too large
    }
    unsigned char *buffer = (unsigned char *)malloc(ssl->d1->mtu);
    if (!buffer) {
        return -1; // Memory allocation failed
    }
    memcpy(buffer, packet, packet_len); // Vulnerable: No check if packet_len exceeds buffer's capacity
    // Process packet ...
    free(buffer);
    return 0;
}

