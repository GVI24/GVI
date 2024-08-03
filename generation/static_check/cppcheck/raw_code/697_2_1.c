static int parse_message_packet(NetworkContext *net_ctx, void *packet, int packet_size) {
    const uint8_t *packet_data = packet;
    Message *msg = net_ctx->message;
    
    if (packet_size < 6) {
        return -1; // Not enough data for message header
    }

    // Vulnerable to buffer overflow
    printf("Message packet header: %x %x %x %x %x %x\n",
           packet_data[0], packet_data[1], packet_data[2], packet_data[3], packet_data[4], packet_data[5]);

    // Message parsing logic...

    return 0;
}

