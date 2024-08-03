void encode_block(int16_t *pixels, int width, int height, int16_t *encoded) {
    int i, j;
    int16_t temp[256]; // Assuming max size 16x16
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            // May cause overflow if width or height exceed 16
            temp[j + i * width] = pixels[i * width + j];
        }
    }
    // Encoding logic that could be affected by overflow in temp[]
    // ...
}
