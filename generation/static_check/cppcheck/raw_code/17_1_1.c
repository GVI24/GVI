static void grayscale_to_rgb(uint8_t *input, uint8_t *output, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            uint8_t gray = *input++;
            *output++ = gray; // Red
            *output++ = gray; // Green
            *output++ = gray; // Blue
        }
    }
}

