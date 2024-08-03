static int parse_video_packet(AVCodecContext *avctx, AVPacket *pkt) {
    VideoParseContext * const vpc = avctx->priv_data;
    const uint8_t *packet_data = pkt->data;
    int packet_size = pkt->size;
    
    av_fast_malloc(&vpc->parse_buffer, &vpc->parse_buffer_size, packet_size);
    if (!vpc->parse_buffer) return AVERROR(ENOMEM);

    // Vulnerable copying without bounds checking
    for (int i = 0; i < packet_size; i++) {
        vpc->parse_buffer[i] = packet_data[i]; // Simple copy
    }

    // Parsing logic...
    return 0;
}