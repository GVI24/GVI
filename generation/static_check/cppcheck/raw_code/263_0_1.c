void apply_brightness_filter(int16_t *input, uint8_t *image, int width, int height, int brightness) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int new_value = image[x] + brightness;
            image[x] = (new_value > 255) ? 255 : ((new_value < 0) ? 0 : new_value);
        }
        image += width; // No check if 'image' pointer exceeds buffer size
    }
}

