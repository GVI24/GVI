static void render_image(ImageContext *img_ctx, int16_t (*matrix)[64], int img_x, int img_y) {
    int img_stride = img_ctx->image.stride;
    uint8_t *target_pixel = img_ctx->image.pixels + (img_y * img_stride * 2) + (img_x * 2);

    // No bounds checking on img_x, img_y can cause a write overflow
    for (int j = 0; j < 16; j += 2) {
        memcpy(target_pixel + j * img_stride, matrix[j / 2], 16);
    }
}

