void transform_image_block(const int16_t *coeffs, uint8_t *image, int img_width) {
    int16_t block[64];
    for (int i = 0; i < 8; i++) {
        // Direct copy of coefficients without bounds checking could lead to buffer overflow
        memcpy(block + i * 8, coeffs + i * 8, 8 * sizeof(int16_t));
    }
    // Apply transformation to the block (dummy operation for illustration)
    for (int i = 0; i < 64; i++) {
        block[i] = block[i] / 2;
    }
    // No validation of img_width leads to potential buffer overflow when writing to image
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            image[i * img_width + j] += block[i * 8 + j];
        }
    }
}

