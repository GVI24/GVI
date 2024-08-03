static void overlay_image(ImageContext *ctx, int img_x, int img_y) {
    int stride = ctx->dest_img.stride;
    uint8_t *dest_pixels = ctx->dest_img.pixels + (img_y * stride) + img_x;
    uint8_t *source_pixels = ctx->source_img.pixels;

    for (int y = 0; y < ctx->source_img.height; y++) {
        for (int x = 0; x < ctx->source_img.width; x++) {
            dest_pixels[x] = source_pixels[x]; // Potential out-of-bounds write
        }
        dest_pixels += stride;
        source_pixels += ctx->source_img.width;
    }
}