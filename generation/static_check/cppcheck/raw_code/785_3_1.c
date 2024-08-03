void rgb_to_grayscale(uint8_t *rgb_image, uint8_t *gray_image, int num_pixels, int color_map_size) {
    int grayscale_value;
    for (int i = 0; i < num_pixels; i++) {
        grayscale_value = (int)(0.3 * rgb_image[i * 3] + 0.59 * rgb_image[i * 3 + 1] + 0.11 * rgb_image[i * 3 + 2]);
        if (grayscale_value >= color_map_size) grayscale_value = color_map_size - 1; // Insufficient bounds check
        gray_image[i] = grayscale_value; // Could lead to buffer overflow if gray_image is not sized appropriately
    }
}