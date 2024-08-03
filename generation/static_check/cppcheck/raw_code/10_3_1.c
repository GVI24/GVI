void unchecked_packet_processing(char *packet, char *buffer, int buffer_size) {
    int packet_size;
    // Assume first 2 bytes of packet contain size information
    packet_size = (packet[0] << 8) | packet[1];
    
    // No validation if packet_size exceeds buffer_size,
    // leading to a possible buffer overflow
    memcpy(buffer, packet + 2, packet_size);
}
