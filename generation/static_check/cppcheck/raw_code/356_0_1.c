void copy_image_data(FrameContext *ctx, int x, int y) {
    uint8_t *src = ctx->source_data + (y * ctx->width + x) * ctx->channels;
    uint8_t *dest = ctx->frame_buffer;
    int i, j;

    for (i = 0; i < ctx->height; i++) {
        for (j = 0; j < ctx->width * ctx->channels; j++) {
            dest[i * ctx->width * ctx->channels + j] = src[i * ctx->width * ctx->channels + j];
        }
    }
}

