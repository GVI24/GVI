void copy_rgb_values(uint8_t *source, uint8_t *destination, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        destination[i * 3] = source[i * 3];       // Red value
        destination[i * 3 + 1] = source[i * 3 + 1]; // Green value
        destination[i * 3 + 2] = source[i * 3 + 2]; // Blue value
        // Potential out-of-bounds read/write if source or destination is too small
    }
}

