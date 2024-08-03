// Vulnerability: Buffer Overflow with fixed-size stack allocation
void process_packet(char *packet_data, int data_length) {
    char packet_buffer[1024];
    int header_size = 12; // let's assume header size is a constant 12 bytes
    // Dangerous: No check for data_length exceeding packet_buffer size
    memcpy(packet_buffer + header_size, packet_data, data_length);
    // ... process the packet
}