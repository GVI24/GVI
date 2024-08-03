void enhance_contrast(uint8_t *pixels, int count, uint8_t min_val, uint8_t max_val) {
    uint8_t temp_pixels[512]; // Buffer with limited size
    for (int i = 0; i < count; i++) {
        // Potential buffer overflow if count > 512
        if (pixels[i] < min_val) {
            temp_pixels[i] = min_val;
        } else if (pixels[i] > max_val) {
            temp_pixels[i] = max_val;
        } else {
            temp_pixels[i] = pixels[i];
        }
    }
    // Copy enhanced pixels back
    for (int i = 0; i < count; i++) {
        pixels[i] = temp_pixels[i];
    }
}
