void image_brightness_adjust(uint8_t *pixels, int width, int height, int brightness) {
    int num_pixels = width * height;
    for (int i = 0; i < num_pixels; ++i) {
        // Vulnerable to integer overflow
        int new_value = pixels[i] + brightness;
        pixels[i] = (uint8_t) ((new_value > 255) ? 255 : ((new_value < 0) ? 0 : new_value));
    }
}
