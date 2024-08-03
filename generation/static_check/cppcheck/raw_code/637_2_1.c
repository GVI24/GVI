void handle_network_packet(NetworkContext *net_ctx, const char *packet, int packet_size) {
    int header_size = net_ctx->header_size;
    if (packet_size < header_size) {
        printf("Packet too small\n");
        return;
    }
    char buffer[MAX_PACKET_SIZE];
    int payload_size = packet_size - header_size;
    // Potential for buffer overflow if payload_size is larger than MAX_PACKET_SIZE
    memcpy(buffer, packet + header_size, payload_size);
    net_ctx->process_packet(net_ctx, buffer, payload_size);
}

