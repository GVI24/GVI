static int decode_frame_16bit_color(OpVideoContext *ctx) {
    int i, j;
    uint16_t *frame_buffer = (uint16_t*)ctx->frame_buffer;
    for (i = 0; i < ctx->height; i++) {
        for (j = 0; j < ctx->width; j += 2) {
            frame_buffer[j] = frame_buffer[j + 1] = get_next_value_16bit(&ctx->stream);
        }
        frame_buffer += ctx->line_size;
    }
    return 0;
}

