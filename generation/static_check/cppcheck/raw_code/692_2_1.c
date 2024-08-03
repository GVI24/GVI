typedef struct {
    unsigned char *payload;
    unsigned int length;
} network_packet;

void handle_network_packet(network_packet *pkt) {
    unsigned int header_len;
    unsigned char buffer[128];
    
    if (pkt->length >= 4) {
        header_len = pkt->payload[2] + (pkt->payload[3] << 8); // Incorrectly assuming 2-byte header
        // No check to verify that header_len is within buffer limits
        memcpy(buffer, pkt->payload + 4, header_len);
    }
    // ... handle the packet ...
}