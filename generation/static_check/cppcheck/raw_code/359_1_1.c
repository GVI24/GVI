void vp9_idct_add_c(const int16_t* input, uint8_t* dest, int stride) {
    int16_t out[64];
    int16_t* outptr = &out[0];
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            outptr[j * 8 + i] = input[i * 8 + j];
        }
    }
    vp9_idct8x8_64_add_c(out, dest, stride);

    for (i = 0; i < 8 * stride; i += stride) {
        for (j = 0; j < 8; j++) {
            dest[i + j] = clip_pixel(dest[i + j] + out[i + j]);
        }
    }
}