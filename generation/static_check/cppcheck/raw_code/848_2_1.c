void copy_packet_data(NETWORK_PACKET *packet, char *dest, int dest_size) {
    if (packet->size > dest_size) {
        printf("Packet size too large to copy!\n");
        return;
    }
    // Missing bounds check can lead to buffer overflow
    memcpy(dest, packet->data, packet->size); 
}

