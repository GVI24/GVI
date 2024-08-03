static void fast_fill(struct gfx_context *ctx, int x, int y, int width, int height, uint32_t color) {
    int screen_width = ctx->width;
    uint8_t *video_mem = ctx->video_memory;
    uint8_t color_array[4];
    color_array[0] = color;
    color_array[1] = color >> 8;
    color_array[2] = color >> 16;
    color_array[3] = color >> 24;

    // No bounds checking can cause an overflow when filling the last line
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            memcpy(&video_mem[(y + i) * screen_width + (x + j) * 4], color_array, 4);
        }
    }
}

