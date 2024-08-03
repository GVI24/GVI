static int compute_image_histogram(ImageContext *ctx, uint8_t *histogram) {
    int x, y;
    for (y = 0; y < ctx->height; y++) {
        for (x = 0; x < ctx->width; x++) {
            uint8_t pixel_value = ctx->image_data[x + y * ctx->width];
            histogram[pixel_value]++; // Potential buffer overflow if pixel_value >= histogram size
        }
    }

    return 0;
}

