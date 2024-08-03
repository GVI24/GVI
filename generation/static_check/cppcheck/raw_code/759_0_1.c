static void apply_chroma_key(VideoContext *ctx, uint8_t chroma_key[3], int start, int end) {
    int x, y;
    int width = ctx->frame_width;
    int height = ctx->frame_height;
    int stride = ctx->frame_data.linesize[0];
    uint8_t *data = ctx->frame_data.data[0];
    data += start * width * stride;

    for (y = start; y < end; y++) {
        for (x = 0; x < width; x++) {
            int pixel = y * width + x;
            if (data[pixel * 3] == chroma_key[0] &&
                data[pixel * 3 + 1] == chroma_key[1] &&
                data[pixel * 3 + 2] == chroma_key[2]) {
                // Replace chroma key color with transparency
                data[pixel * 4] = 0x00;
                data[pixel * 4 + 1] = 0x00;
                data[pixel * 4 + 2] = 0x00;
                data[pixel * 4 + 3] = 0x00;
            }
        }
    }
}

