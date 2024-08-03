static void process_network_packet(void *net_device, unsigned char *packet_data, size_t packet_size) {
    NetworkDevice *network = net_device;
    unsigned char packet_type = packet_data[0];
    if (packet_type >= MAX_PACKET_HANDLERS) {
        return;
    }
    if (network->handlers[packet_type]) {
        network->handlers[packet_type](network->handler_data[packet_type], packet_data, packet_size);
    }
}

