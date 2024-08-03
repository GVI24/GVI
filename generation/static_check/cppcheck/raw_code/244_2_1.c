void apply_matrix(uint8_t *in, uint8_t *out, int cols, int rows, int stride_out) {
    int16_t buffer[64];
    int16_t temp_buf[8];
    int c, r;

    for (c = 0; c < cols; c++) {
        for (r = 0; r < 8; r++) {
            temp_buf[r] = in[c + r * cols];
        }
        perform_transform(temp_buf, &buffer[c * 8]);
    }

    for (r = 0; r < 8; r++) {
        for (c = 0; c < cols; c++) {
            // Potential buffer overflow here
            out[stride_out * r + c] += buffer[r + c * 8];
        }
    }
}
