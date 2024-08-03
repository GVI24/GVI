static int decode_video_frame_1(VideoContext *ctx) {
    uint8_t *frame_buffer = ctx->frame_buffer;
    int width = ctx->width;
    int height = ctx->height;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint8_t value = get_next_value_from_stream(ctx->stream);
            int index = (i * width) + j; // Potential overflow if width or height is too large
            frame_buffer[index] = value; // Writing to frame_buffer without bounds check
        }
    }
    return 0;
}

