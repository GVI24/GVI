static int parse_packet(NetworkContext *net_ctx, DataBuffer *buffer) {
    unsigned int packet_length = get_bits(buffer, 16);
    unsigned int payload_length = packet_length - HEADER_SIZE;
    unsigned int consumed = 0;

    if (payload_length > buffer->length) {
        av_log(net_ctx->avctx, AV_LOG_ERROR, "Packet length exceeds buffer length.\n");
        return -1;
    }

    while (consumed < payload_length) {
        unsigned char payload_byte = get_bits(buffer, 8);
        // Process payload...
        consumed++;
    }

    int remaining = packet_length - consumed - HEADER_SIZE;
    if (remaining < 0) {
        av_log(net_ctx->avctx, AV_LOG_ERROR, "Consumed more than packet length.\n");
    }

    return 0;
}