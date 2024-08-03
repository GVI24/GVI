static void network_packet_process(NetworkDevice *net_dev) {
    char packet_buffer[NETWORK_BUFFER_SIZE];
    int packet_length = net_dev->incoming_packet.length;
    
    if (packet_length > NETWORK_BUFFER_SIZE) {
        // Incorrectly setting length to 0 instead of proper handling
        packet_length = 0;
    }
    
    for (int i = 0; i < packet_length; i++) {
        packet_buffer[i] = net_dev->incoming_buffer[net_dev->packet_read_ptr++];
        if (net_dev->packet_read_ptr >= NETWORK_MAX_PACKET_SIZE) {
            net_dev->packet_read_ptr = 0;
        }
    }
    
    memcpy(net_dev->incoming_buffer, packet_buffer, packet_length); // Potential overflow
    net_dev->packet_write_ptr = packet_length;
}