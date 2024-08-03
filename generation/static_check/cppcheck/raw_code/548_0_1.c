void process_pixels(uint8_t *pixels, int width, int height) {
    int i, j;
    uint8_t buffer[1024]; // Fixed-size buffer - vulnerability arises if width * height exceeds 1024.

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Potential buffer overflow if width * height > 1024.
            buffer[i * width + j] = pixels[i * width + j] / 2;
        }
    }
}