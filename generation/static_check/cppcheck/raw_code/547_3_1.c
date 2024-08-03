int parse_network_packet(const uint8_t *packet, int packet_length) {
    int i;
    uint8_t header[4];
    if (packet_length < 4) return -1; // Not enough data for header

    // Assume the packet header is always 4 bytes - potential over-read
    for (i = 0; i < 4; i++) {
        header[i] = packet[i];
    }
    
    // Processing data without checking packet_length
    for (i = 4; i < packet_length; i++) {
        // Possible over-read of 'packet' array
        uint8_t data = packet[i + 2] - packet[i]; 
    }
    return 0;
}