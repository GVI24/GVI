void rgb_to_grayscale(uint8_t *rgb_image, uint8_t *gray_image, int pixel_count) {
    int i;
    for (i = 0; i < pixel_count; i++) {
        int r = rgb_image[3*i];     // Red
        int g = rgb_image[3*i + 1]; // Green
        int b = rgb_image[3*i + 2]; // Blue
        gray_image[i] = (r + g + b) / 3; // Average to get grayscale; no bounds check
    }
}

