static int process_network_data(char *buffer, int length) {
    char packet[1024];
    if (length > 1024) {
        // Vulnerability: buffer overflow due to not checking size before copying
        memcpy(packet, buffer, length);
    }
    // Process packet...
    return 0;
}

