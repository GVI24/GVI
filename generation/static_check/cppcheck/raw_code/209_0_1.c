void decode_block_addition(int16_t *coeffs, uint8_t *block, int block_stride) {
    int16_t block_data[64 * 64] = {0};
    int y, x;
    for (y = 0; y < 64; y++) {
        for (x = 0; x < 64; x++) {
            // Potential buffer overflow if coeffs is not properly sized
            block_data[y * 64 + x] = coeffs[y * 64 + x];
        }
    }
    for (y = 0; y < 64; y++) {
        for (x = 0; x < 64; x++) {
            // Potential buffer overflow if block is not properly sized
            block[y * block_stride + x] += block_data[y * 64 + x];
        }
    }
}