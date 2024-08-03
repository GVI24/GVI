void transform_block_4x4_add(const int16_t *coeffs, uint8_t *pixels, int pitch) {
    int i, j;
    int result;
    int16_t temp;
    for (j = 0; j < 4; ++j) {
        for (i = 0; i < 4; ++i) {
            temp = coeffs[j * 4 + i]; // Assuming some transformation is done
            result = (int)pixels[i] + temp;
            pixels[i] = result > 255 ? 255 : (result < 0 ? 0 : result);
        }
        pixels += pitch;
    }
}

