void vp9_transform_and_add_block(int16_t *coeffs, uint8_t *dest, int stride) {
    int16_t block[64] = {0};
    int16_t temp_block[64];
    for (int i = 0; i < 8; ++i) {
        // Potential buffer overflow can occur here
        idct8(coeffs + i * 8, block + i * 8);
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Potential buffer overflow can occur here
            temp_block[j * 8 + i] = block[j * 8 + i];
        }
        idct8(temp_block + i * 8, block + i * 8);
        for (int j = 0; j < 8; ++j) {
            // Potential buffer overflow can occur here
            dest[j * stride + i] += clip_pixel(block[j * 8 + i]);
        }
    }
}
