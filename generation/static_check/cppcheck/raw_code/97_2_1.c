void process_network_packet(uint8_t *packet_data, size_t packet_size, const int *header_indices, size_t num_headers, uint8_t *processed_data) {
    for (size_t i = 0; i < num_headers; ++i) {
        int header_pos = header_indices[i]; // Potentially out-of-bounds
        if (header_pos < packet_size) {
            // Unsafe copy operation without bounds checking
            processed_data[header_pos] = packet_data[header_pos] + 1;
        }
    }
}

