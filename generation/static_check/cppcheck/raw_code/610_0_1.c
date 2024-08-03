int my_encode_video_frame_1(MyCodecContext *ctx, AVPacket *pkt, const AVFrame *frame) {
    ctx->buffer_size = 10000; // Arbitrary buffer size, may not be sufficient
    ctx->buffer = malloc(ctx->buffer_size);
    if (!ctx->buffer) {
        return -1; // malloc failure not logged
    }
    // dummy encoding
    memset(ctx->buffer, 0, ctx->buffer_size);
    pkt->data = ctx->buffer;
    pkt->size = ctx->buffer_size; // packet size might be larger than actual encoded data
    return 0;
}

