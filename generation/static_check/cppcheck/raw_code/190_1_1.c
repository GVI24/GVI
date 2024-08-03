void vp9_iht4x4_16_add_c(const int16_t *input, uint8_t *dest, int stride, int tx_type) {
    int i, j;
    int16_t out[4 * 4];
    int16_t *outptr = out;
    int16_t temp_in[4], temp_out[4];
    const transform_2d ht = IHT_4[tx_type];
    for (i = 0; i < 4; ++i) {
        ht.rows(input, outptr);
        input += 4;
        outptr += 4;
    }
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) temp_in[j] = out[j * 4 + i];
        ht.cols(temp_in, temp_out);
        for (j = 0; j < 4; ++j) dest[j * stride + i] = clip_pixel(ROUND_POWER_OF_TWO(temp_out[j], 6) + dest[j * stride + i]);
    }
}