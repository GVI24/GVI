void handle_packet(char *packet_buffer, size_t buffer_len, const char *packet_data, size_t packet_len) {
    size_t offset = 0;
    if (packet_len > 128) { // Hypothetical header size
        offset = 128; // Skip header
    }
    for (size_t i = offset; i < packet_len; i++) {
        if (i < buffer_len) {
            // Missing check, writing past buffer can occur
            packet_buffer[i - offset] = packet_data[i]; // Copy packet data
        }
    }
}