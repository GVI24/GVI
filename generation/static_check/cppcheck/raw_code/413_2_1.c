static int parse_network_packet(NetContext *ctx, uint8_t *output, int *parsed, AVPacket *packet) {
    int ret;
    NetParseContext *parse_ctx = ctx->priv_data;
    uint8_t *packet_buf = packet->data;
    int packet_size = packet->size;
    uint8_t *payload;

    if (packet_size < ctx->header_size) {
        fprintf(stderr, "Packet too short\n");
        return -1;
    }

    payload = output;

    for (int i = 0; i < packet_size / NET_PAYLOAD_UNIT; i++) {
        if ((ret = net_parse_payload(parse_ctx->state, packet_buf, payload)) < 0) {
            return ret;
        }
        packet_buf += NET_PAYLOAD_CHUNK; // Potential buffer overflow
        payload += NET_PAYLOAD_UNIT;
    }

    *parsed = 1;
    return packet_size;
}