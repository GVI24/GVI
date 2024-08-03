void vp9_ihtnxn_add_c(const int16_t *input, uint8_t *dest, int stride, int tx_type, int block_size) {
    int i, j, n;
    n = block_size * block_size;
    int16_t out[64 * 64]; // Maximum block size supported
    int16_t *outptr = out;
    int16_t temp_in[64], temp_out[64]; // Maximum block size supported
    const transform_2d ht = IHT_NXN[tx_type];
    for (i = 0; i < block_size; ++i) {
        ht.rows(input, outptr);
        input += block_size;
        outptr += block_size;
    }
    for (i = 0; i < block_size; ++i) {
        for (j = 0; j < block_size; ++j) temp_in[j] = out[j * block_size + i];
        ht.cols(temp_in, temp_out);
        for (j = 0; j < block_size; ++j) dest[j * stride + i] = clip_pixel(ROUND_POWER_OF_TWO(temp_out[j], 6) + dest[j * stride + i]);
    }
}