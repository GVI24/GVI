void vp9_iht32x32_1024_add_c(const int16_t *input, uint8_t *dest, int stride, int tx_type) {
    int i, j;
    int16_t out[32 * 32];
    int16_t *outptr = out;
    int16_t temp_in[32], temp_out[32];
    const transform_2d ht = IHT_32[tx_type];
    for (i = 0; i < 32; ++i) {
        ht.rows(input, outptr);
        input += 32;
        outptr += 32;
    }
    for (i = 0; i < 32; ++i) {
        for (j = 0; j < 32; ++j) temp_in[j] = out[j * 32 + i];
        ht.cols(temp_in, temp_out);
        for (j = 0; j < 32; ++j) dest[j * stride + i] = clip_pixel(ROUND_POWER_OF_TWO(temp_out[j], 6) + dest[j * stride + i]);
    }
}