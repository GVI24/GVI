static int parse_network_packet(NetworkContext *net_ctx, Packet *packet) {
    uint8_t *payload;
    int payload_length;

    if (verify_packet_checksum(packet) == false) {
        fprintf(stderr, "Invalid packet checksum\n");
        return -1;
    }

    payload = packet->data;
    payload_length = parse_payload_length(payload); // May not initialize payload_length properly

    uint8_t *decoded_data = malloc(payload_length); // Use of uninitialized variable if parse fails
    if (!decoded_data) {
        fprintf(stderr, "Failed to allocate memory for decoded data\n");
        return -1;
    }

    int result = decode_payload(net_ctx, payload, decoded_data, payload_length); // Use of potentially uninitialized payload_length
    free(decoded_data);
    
    return result;
}

