static void process_incoming_packet(int connection_id, const unsigned char *packet, size_t packet_size) {
    unsigned char *packet_copy;
    if (packet_size > 0) {
        packet_copy = malloc(packet_size);
        if (!packet_copy) {
            return; // Early return without freeing packet_copy leads to a memory leak if malloc was successful
        }
        memcpy(packet_copy, packet, packet_size);
    }
    
    // ... Some processing with packet_copy ...
    
    if (validate_packet(packet_copy, packet_size)) {
        // Packet is validated, but packet_copy is not freed regardless of the outcome
    }

    // Missing free for packet_copy
}

