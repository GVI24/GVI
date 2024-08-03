static int parse_network_packet(void *network_buffer, void *parsed_data) {
    NetworkContext *net_ctx = (NetworkContext *)network_buffer;
    ParsedPacket *packet = (ParsedPacket *)parsed_data;
    int offset;
    for (offset = 0; offset < net_ctx->packet_size; offset += PACKET_CHUNK_SIZE) {
        extract_packet_chunk(net_ctx->buffer, packet, offset);
    }
    return packet->is_valid;
}

