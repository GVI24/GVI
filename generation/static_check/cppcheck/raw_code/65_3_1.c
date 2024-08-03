static void adjust_pixel_contrast(uint8_t *pixels, int num_pixels, uint8_t contrast_value) {
    int i;
    for (i = 0; i < num_pixels; i++) {
        // Vulnerable: Potential integer overflow if 'contrast_value' is large
        pixels[i] *= contrast_value;
        // Vulnerable: No bounds checking for array 'pixels'
    }
}