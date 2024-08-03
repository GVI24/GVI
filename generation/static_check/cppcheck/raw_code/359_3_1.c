void vp9_fwht4x4_c(const int16_t* input, int16_t* output, int stride) {
    int16_t out[16];
    int16_t temp[16];
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            temp[j + i * 4] = input[j * stride + i];
        }
        fwht4(temp + i * 4, out + i * 4);
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            output[j * 4 + i] = out[i * 4 + j];
        }
    }
}