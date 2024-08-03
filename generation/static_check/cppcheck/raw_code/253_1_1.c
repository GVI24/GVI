static void encode_video_stream(EncoderContext *enc, int16_t (*coeffs)[64], int bx, int by) {
    int line_size = enc->output.line_size;
    uint8_t *output_buf = enc->output.data + (by * 16 * line_size) + (bx * 16);

    // Vulnerability: No check for bx, by leading to potential buffer overflow
    for (int i = 0; i < 4; i++) {
        custom_idct_write(output_buf + i * 8, line_size, coeffs[i]);
    }
}

