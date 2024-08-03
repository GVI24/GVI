static void rle_decode_frame(uint8_t *input, uint8_t *output, int width, int height) {
    int x = 0, y = 0;
    while (y < height) {
        uint8_t count = *input++;
        uint8_t value = *input++;
        for (int i = 0; i < count; i++) {
            *output++ = value; // Assuming single-channel grayscale for simplicity
            x++;
            if (x >= width) {
                y++;
                x = 0;
            }
        }
    }
}