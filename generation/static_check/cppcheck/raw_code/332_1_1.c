static int parse_packet_data (char *packet, int start, unsigned char *data) {
    int len = strlen(packet);
    if (start < 0 || start >= len) {
        // Handle error: start index out of bounds
        return -1;
    }

    *data = packet[start];
    // No bounds check on start + 1; could read past the end of the packet
    *data |= (packet[start + 1] << 8);

    return start + 2;
}
