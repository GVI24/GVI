void apply_filter(const float *coefficients, uint8_t *image, int width, int height) {
    int x, y;
    float pixel_value;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixel_value = image[x + y * width] * coefficients[0]; // No bounds checking
            image[x + y * width] = (uint8_t)pixel_value;  // Potential overflow
        }
    }
}
