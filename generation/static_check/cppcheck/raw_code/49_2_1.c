#define MAX_PACKET_SIZE 4096
static int network_packet_parse(NetworkContext *netctx, const uint8_t *packet_data, size_t packet_size) {
    if (packet_size > MAX_PACKET_SIZE) {
        return -1; // Packet size too large but not checking if too small
    }

    int header_size = extract_header_size(packet_data); // Assume this function exists
    if (header_size > packet_size) {
        return -1; // Header size overflows
    }

    const uint8_t *payload = packet_data + header_size;
    size_t payload_size = packet_size - header_size;

    // Process payload
    while (payload_size--) {
        netctx->buffer[netctx->buffer_index++] = *payload++; // No check on buffer_index
    }

    return 0;
}

