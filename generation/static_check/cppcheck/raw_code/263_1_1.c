void inverse_quantize_block_16x16(const int16_t *coeffs, uint8_t *block, int block_stride) {
    int i, j;
    int dequant_value;
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            dequant_value = coeffs[i] * 10; // Simplified dequantization
            block[i] = clip_pixel(block[i] + dequant_value);
        }
        block += block_stride; // No check if 'block' pointer goes out of bounds
    }
}

