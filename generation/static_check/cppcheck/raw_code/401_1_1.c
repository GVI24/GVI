void inverse_dct_process(int16_t *block, uint8_t *output_frame, int line_stride, int dct_type) {
    int u, v;
    int16_t result_block[16];
    int16_t temp_block[4], res_line[4];
    transform_2d idct = INVERSE_DCT[dct_type];
    
    for (u = 0; u < 4; ++u) {
        idct.rows(block + u * 4, result_block + u * 4); // Possible out-of-bounds read
    }
    
    for (u = 0; u < 4; ++u) {
        for (v = 0; v < 4; ++v) temp_block[v] = result_block[v * 4 + u];
        idct.cols(temp_block, res_line);
        for (v = 0; v < 4; ++v) output_frame[v * line_stride + u] += res_line[v]; // Possible out-of-bounds write
    }
}

