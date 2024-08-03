void vp9_iht4x4_16_add_c(const tran_low_t* input, uint8_t* dest, int stride, int tx_type) {
    tran_low_t out[16];
    tran_low_t* outptr = &out[0];
    int i, j;
    const transform_2d ht = IHT_4[tx_type];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) outptr[j * 4 + i] = input[i * 4 + j];
        ht.rows(outptr + i * 4, outptr + i * 4);
    }
    for (i = 0; i < 4; i++) {
        ht.cols(outptr + i, outptr + i);
        for (j = 0; j < 4; j++) dest[i * stride + j] = clip_pixel(dest[i * stride + j] + out[i * 4 + j]);
    }
}