void process_network_packet(NetworkPacket *pkt, char *data, int data_length) {
    char packet_data[128];
    int packet_length = pkt->length; // pkt->length comes from an external source and is not validated.
    if (packet_length > sizeof(packet_data)) {
        printf("Error: Packet length too large\n");
        return;
    }
    memcpy(packet_data, data, packet_length); // Possible buffer overflow if packet_length is too large.
    // Continue processing packet_data...
}