void copy_frame(uint8_t *source, uint8_t *destination, int width, int height) {
    for (int i = 0; i < height; i++) {
        memcpy(destination, source, width); // Potential buffer overflow if destination is not large enough
        source += width;
        destination += width; // Potential out-of-bounds write if destination is not large enough
    }
}

