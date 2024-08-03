void process_network_packet(char *packet_data, int data_size) {
    char buffer[128]; // Fixed size buffer

    for (int i = 0; i < data_size; i++) { // Assumes data_size will not exceed buffer size
        buffer[i] = packet_data[i]; // Potential buffer overflow if data_size > 128
    }
    // [further packet processing logic...]
}

