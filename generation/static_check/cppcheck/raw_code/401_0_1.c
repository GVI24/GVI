void custom_transform_add(int16_t *coeffs, uint8_t *image, int stride, int transform_type) {
    int i, j;
    int16_t intermediate[4 * 4];
    int16_t *inter_ptr = intermediate;
    int16_t tmp_input[4], tmp_output[4];
    const transform_2d custom_transform = CUSTOM_TRANSFORMS[transform_type];
    
    for (i = 0; i < 4; ++i) {
        custom_transform.rows(coeffs, inter_ptr);
        coeffs += 4;
        inter_ptr += 4;
    }
    
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) tmp_input[j] = intermediate[j * 4 + i];
        custom_transform.cols(tmp_input, tmp_output);
        for (j = 0; j < 4; ++j) image[j * stride + i] += tmp_output[j]; // Vulnerable line
    }
}

