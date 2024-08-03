#define PACKET_BUFFER_SIZE 1024
void craft_network_packet(const char *packet_data) {
    char packet_buffer[PACKET_BUFFER_SIZE];
    char *packet_ptr = packet_buffer;
    int header_size = snprintf(packet_ptr, PACKET_BUFFER_SIZE, "Header: Packet Length - %zu ", strlen(packet_data));
    
    // Unsafe: No check for remaining space in packet_buffer before appending data
    snprintf(packet_ptr + header_size, PACKET_BUFFER_SIZE - header_size, "Data: %s", packet_data);
    
    // Code to send network packet
    // ...
}

