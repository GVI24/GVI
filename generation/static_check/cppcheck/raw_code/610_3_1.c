int my_encode_video_frame_4(MyCodecContext *ctx, AVPacket *pkt, const AVFrame *frame, enum AVPixelFormat format) {
    ctx->buffer_size = 1024; // Hardcoded buffer size
    ctx->buffer = malloc(ctx->buffer_size);
    if (format != AV_PIX_FMT_YUV420P) {
        free(ctx->buffer); // Free buffer but return success (0), error condition not properly signaled
        return 0; // Should return an error instead
    }
    // Assume the frame is always in YUV420P format
    // Encoding logic...
    pkt->data = ctx->buffer;
    pkt->size = ctx->buffer_size;
    return 0;
}