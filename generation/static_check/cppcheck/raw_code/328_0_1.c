static int video_decode_color_indices(VideoContext *ctx) {
    int i, j;
    uint16_t color[4];
    uint16_t *framebuffer = (uint16_t *)ctx->framebuffer;

    for (i = 0; i < 8; i++) {
        if (i % 4 == 0) {
            for (j = 0; j < 4; j++) {
                color[j] = bytestream2_get_le16(&ctx->stream_ptr);
            }
        }
        for (j = 0; j < 8; j++) {
            framebuffer[j] = color[j / 2];
        }
        framebuffer += ctx->line_stride;
    }
    return 0;
}

