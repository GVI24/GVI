static int apply_packet_filter(NetworkContext *n, uint8_t *packet_data) {
    int i;
    for (i = 0; i < n->packet_size; i++) {
        uint8_t filter_type = n->filter_map[i];
        packet_data[i] = apply_filter_type(filter_type, packet_data[i]); // Potential buffer overflow
    }
    // Further packet processing...
    return 0;
}

// Helper function for Example 4 (not necessarily vulnerable, but part of the application scenario)
uint8_t apply_filter_type(uint8_t filter_type, uint8_t data) {
    // Filter logic (irrelevant for the vulnerability demonstration)
    return (filter_type * data) % 256;
}