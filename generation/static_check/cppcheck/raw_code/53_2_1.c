void get_packet_size_distribution(Packet **packets, int num_packets, int size_hist[MAX_PACKET_SIZE]) {
    for (int i = 0; i < num_packets; i++) {
        Packet *packet = packets[i];
        int size = packet ? packet->size : 0;
        // Potential null pointer dereference and out-of-bounds access.
        size_hist[size]++;
    }
}

