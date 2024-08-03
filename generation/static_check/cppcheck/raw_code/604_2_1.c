void adjust_brightness(int *image_data, int total_pixels, int adjustment) {
    for (int i = 0; i <= total_pixels; ++i) { // Should be i < total_pixels
        image_data[i] += adjustment; // No bounds check, potential off-by-one
    }
}

