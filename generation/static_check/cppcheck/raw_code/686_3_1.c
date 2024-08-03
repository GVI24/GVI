void process_packets(Packet *packets, int num_packets) {
    int i, data_size;
    char buffer[256];
    
    for (i = 0; i < num_packets; i++) {
        data_size = packets[i].data_size;
        if (data_size > 256) {
            // Potential buffer overflow due to large data size
            data_size = 256;
        }
        memcpy(buffer, packets[i].data, data_size);
        // Process buffer...
    }
}