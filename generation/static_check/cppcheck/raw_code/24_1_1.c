void decode_and_render_frame(const int16_t *input, uint8_t *frame, int width, int height) {
    int16_t coeffs[16][16];
    for (int y = 0; y < height; y += 16) {
        for (int x = 0; x < width; x += 16) {
            decode_block(input, coeffs);
            input += 16 * 16;
            for (int i = 0; i < 16; ++i) {
                for (int j = 0; j < 16; ++j) {
                    // Potential buffer overflow can occur here
                    frame[(y + i) * width + x + j] += coeffs[i][j];
                }
            }
        }
    }
}
