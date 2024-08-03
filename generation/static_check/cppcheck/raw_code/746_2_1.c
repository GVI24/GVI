void process_network_packet(NetworkContext *net_ctx, char *packet_data, int size) {
    int packet_idx = net_ctx->current_packet_index; // No bounds checking here
    char *packet_buffer = net_ctx->packet_buffer + packet_idx * net_ctx->max_packet_size;
    for (int i = 0; i < size; i++) {
        packet_buffer[i] = packet_data[i]; // Possible buffer overflow vulnerability
    }
    net_ctx->current_packet_index++;
}

