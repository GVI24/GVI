/* Vulnerable pattern: Buffer Overflow */
void parse_network_packet(char *packet, int size) {
    int offset = 0;
    char packet_info[64];
    
    while (offset < size) {
        // Potential buffer overflow if offset exceeds the packet buffer size.
        memcpy(packet_info, packet + offset, sizeof(packet_info));
        offset += sizeof(packet_info);
        printf("Packet Info: %s\n", packet_info);
    }
}