void decode_network_packet(const char *packet_data, char *decoded_data, int packet_size) {
    char internal_buffer[128];
    int i;

    // Vulnerability: No validation for packet_size, which may lead to buffer overflow
    for (i = 0; i < packet_size; i++) {
        internal_buffer[i] = packet_data[i] ^ 0x40; // Suppose it's some decoding logic
    }

    // Simplified decoding implementation
    for (i = 0; i < 128; i++) {
        decoded_data[i] = internal_buffer[i] - 0x40;
    }
}