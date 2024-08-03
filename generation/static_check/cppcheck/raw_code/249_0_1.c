static int decode_frame(YopDecContext *ctx, int frame_size) {
    if (ctx->buffer_end - ctx->buffer < frame_size) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Incomplete frame data.\n");
        return AVERROR_INVALIDDATA;
    }
    for(int i = 0; i < frame_size; i += 2) {
        ctx->framebuf[i] = ctx->buffer[i]; // Potential out-of-bounds write
    }
    ctx->buffer += frame_size;
    return 0;
}

