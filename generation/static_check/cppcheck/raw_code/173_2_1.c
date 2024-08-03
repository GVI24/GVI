static void network_packet_handle(NetworkContext *net_ctx, Packet *pkt) {
    // Missing NULL check for 'net_ctx' and 'pkt'
    net_ctx->packet_counter++;
    // Potential Use After Free if 'pkt->data' has been freed elsewhere
    process_packet_data(net_ctx->processor, pkt->data, pkt->size);
    // Assuming 'packet_log' is a fixed size array, potential Buffer Overflow
    sprintf(net_ctx->packet_log, "Received packet size: %d", pkt->size);
    // Packet acknowledgment, potentially can underflow if 'net_ctx->acknowledge' is 0
    net_ctx->acknowledge--;
}
