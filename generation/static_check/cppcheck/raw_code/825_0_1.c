void init_frame_data(FrameContext *ctx) {
    if (ctx->frame_size > MAX_FRAME_SIZE) {
        // Potential buffer overflow if frame_data is not large enough
        memset(ctx->frame_data, 0, ctx->frame_width * ctx->frame_height);
    }
}

