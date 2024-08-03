int handle_data_packet(unsigned char *packet, size_t packet_length) {
    size_t data_size;
    char data_buffer[512];

    // Incorrectly assuming the first size_t bytes of packet contain the data size
    data_size = *((size_t *)packet);

    // Vulnerability: No check if data_size is too large for the data_buffer
    if (data_size > packet_length - sizeof(data_size)) {
        return -1; // Correct check for packet_length but not for data_buffer
    }

    memcpy(data_buffer, packet + sizeof(data_size), data_size);
    // Process data_buffer...
    
    return 0;
}