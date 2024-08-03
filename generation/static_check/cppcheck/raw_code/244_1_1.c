void inverse_quantize_add(uint8_t *block, uint8_t *frame, int width, int linesize) {
    int16_t tmp_block[64];
    int16_t *tmp_ptr = tmp_block;
    int i, j;

    for (i = 0; i < 8; i++) {
        dequantize(block + i * 8, tmp_ptr + i * 8);
    }

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            // Potential buffer overflow if linesize is too large.
            frame[j * linesize + i] = clamp_pixel_add(frame[j * linesize + i], tmp_block[j * 8 + i]);
        }
    }
}
