int read_network_parameters(const unsigned char *packet, int packet_len) {
    int offset = 0;
    while (offset < packet_len) {
        int tag = packet[offset++];
        int tag_len = packet[offset++]; // Potential over-read if offset is last byte.
        if (offset + tag_len > packet_len) { // Missing check for tag_len bound
            return -1;
        }
        // Handle tagged parameter...
        offset += tag_len;
    }
    return 0;
}

