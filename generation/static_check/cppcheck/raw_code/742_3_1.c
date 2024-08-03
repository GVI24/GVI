void concatenate_packets(char *buffer, int buffer_size, char **packet_list, int *packet_sizes, int packet_count) {
    int buffer_offset = 0;
    for (int i = 0; i < packet_count; i++) {
        if (packet_sizes[i] < 0 || buffer_offset + packet_sizes[i] > buffer_size) {
            continue; // Should return an error or handle more gracefully
        }
        
        // Unchecked memcpy could lead to buffer overflow
        memcpy(buffer + buffer_offset, packet_list[i], packet_sizes[i]);
        
        buffer_offset += packet_sizes[i];
    }
}