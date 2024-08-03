int process_packet(char *packet, size_t packet_size) {
    char data[256];
    unsigned short data_length;

    // Extract data length from packet (could be controlled by an attacker)
    memcpy(&data_length, packet, sizeof(data_length));

    // Vulnerability: data_length is not validated against the actual packet_size or data buffer size
    memcpy(data, packet + sizeof(data_length), data_length);

    // Process data (omitted)
    return 0;
}

