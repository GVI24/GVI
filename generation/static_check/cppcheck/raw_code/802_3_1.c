static int handle_network_packet(NetworkContext *nc, const uint8_t *packet_data, int packet_size) {
    if (packet_size > nc->buffer_size) {
        av_log(nc->log_ctx, AV_LOG_ERROR, "Packet size exceeds buffer limits.\n");
        return -1;
    }
    if (!nc->packet_buffer) {
        av_log(nc->log_ctx, AV_LOG_ERROR, "Packet buffer is uninitialized.\n");
        return -1;
    }
    // Potentially writing past the buffer if the packet_size is not validated properly
    memcpy(nc->packet_buffer, packet_data, packet_size);
    if (process_packet(nc->processor, nc->packet_buffer, packet_size) < 0) {
        av_log(nc->log_ctx, AV_LOG_ERROR, "Packet processing failed.\n");
        return -1;
    }
    return 0;
}