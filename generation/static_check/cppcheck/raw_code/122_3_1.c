static void parse_network_packet(NetworkContext *ctx, uint8_t *packet, int length) {
    int header_size;
    uint8_t *payload;

    if (length < 2) {
        // Error handling for length < 2, but not for length vs. header_size
        return;
    }

    header_size = packet[1]; // Assumes second byte is header size

    // Does not check if header_size is valid for the given packet length
    payload = (uint8_t *)malloc(header_size);

    memcpy(payload, packet + 2, header_size); // Potential overflow if header_size > length - 2
    process_packet_payload(ctx, payload, header_size);
    free(payload);
}