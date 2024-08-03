int assemble_packet(const void *data_chunks[], size_t sizes[], size_t chunk_count, Network_Packet *packet) {
    size_t total_length = 0;
    for (size_t i = 0; i < chunk_count; ++i) {
        // Potential integer overflow
        total_length += sizes[i];
        if (total_length < sizes[i]) {
            // Overflow occurred, size wrapped around
            return -1;
        }
    }
    if (total_length > MAX_PACKET_SIZE) {
        // Packet too large
        return -1;
    }
    packet->data = malloc(total_length); // Allocation based on potentially incorrect total_length due to overflow
    if (!packet->data) return -1;
    void *write_ptr = packet->data;
    for (size_t i = 0; i < chunk_count; ++i) {
        memcpy(write_ptr, data_chunks[i], sizes[i]);
        write_ptr += sizes[i]; // Potential out-of-bounds write if total_length overflowed
    }
    packet->length = total_length;
    return 0;
}