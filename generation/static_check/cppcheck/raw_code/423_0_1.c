static int decode_frame_header(VideoContext *ctx, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = y * ctx->line_size + x;
            // No bounds check for index
            ctx->frame_header[index] = decode_header_value(ctx);
        }
    }
    return 0;
}
