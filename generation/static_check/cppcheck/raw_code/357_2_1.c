static int parse_network_packet(NetworkContext *netCtx) {
    unsigned char routing_byte;
    int source_node, destination_node;

    routing_byte = bytestream2_get_byte(&netCtx->packet_stream);
    
    // Using routing_byte to calculate network node addresses without bounds checking
    source_node = (routing_byte & 0xF0) >> 4;
    destination_node = (routing_byte & 0x0F);

    printf("Routing Byte: %d, Source: %d, Destination: %d\n", routing_byte, source_node, destination_node);

    return route_packet(netCtx, source_node, destination_node);
}
