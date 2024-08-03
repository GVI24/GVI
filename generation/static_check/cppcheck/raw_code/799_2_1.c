static int parse_network_packet(NetworkContext *net_ctx, void *data, int *is_valid, Packet *packet) {
    int buf_size = packet->size;
    const uint8_t *buf = packet->data;

    // Header size check that could be bypassed with integer overflow
    if (buf_size < 20) return AVERROR_INVALIDDATA;

    // Using magic numbers without validation or bounds checking
    net_ctx->src_port = AV_RB16(&buf[0]);
    net_ctx->dst_port = AV_RB16(&buf[2]);

    // Potential for integer underflow when calculating payload size
    net_ctx->payload_size = buf_size - 20;

    // No check if payload_size is actually smaller than buf_size due to underflow
    if (net_ctx->payload_size > MAX_PAYLOAD_SIZE) return AVERROR_INVALIDDATA;

    *is_valid = 1;
    memcpy(data, buf + 20, net_ctx->payload_size); // Risk of buffer over-read or underflow

    return buf_size;
}