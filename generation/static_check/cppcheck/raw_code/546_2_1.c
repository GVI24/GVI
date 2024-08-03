void decode_network_packet(int packet_id, int total_packets, int *packet_lengths, unsigned char *packet_data) {
    int next_packet_length;
    
    // Potential out-of-bounds read
    if (packet_id < total_packets - 1) {
        next_packet_length = packet_lengths[packet_id + 1];
    }
    
    // ... decode current packet
    
    // Potential out-of-bounds write
    packet_lengths[packet_id] = calculate_packet_length(packet_data);
}

