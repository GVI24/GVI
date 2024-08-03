static void process_frame(FrameContext *ctx, int16_t (*blocks)[64], int block_id) {
    int width = ctx->frame.width;
    int height = ctx->frame.height;
    uint8_t *frame_buffer = ctx->frame.buffer;
    int stride = width;
    int x = (block_id % (width / 8)) * 8;
    int y = (block_id / (width / 8)) * 8;

    // Vulnerability: No bounds check on x or y
    uint8_t *dest = frame_buffer + (y * stride) + x;

    for (int i = 0; i < 8; i++) {
        memcpy(dest + (i * stride), blocks[block_id] + (i * 8), 8);
    }
}

