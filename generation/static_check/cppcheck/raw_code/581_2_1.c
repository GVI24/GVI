static int decode_network_packet(NetworkContext *net_ctx, const uint8_t *packet_data, int packet_size) {
    if (packet_size < 3) {
        fprintf(stderr, "Packet too small\n");
        return -1;
    }
    int payload_size = packet_data[1] | packet_data[2] << 8;
    if (payload_size > packet_size - 3) {
        fprintf(stderr, "Invalid payload size\n");
        return -1;
    }
    net_ctx->packet_type = packet_data[0];
    memcpy(net_ctx->payload, packet_data + 3, payload_size); // Potential buffer overflow, missing size check for payload buffer
    return 0;
}

