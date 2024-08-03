void composite_layers(uint8_t *background, uint8_t *overlay, int width, int height, uint8_t *output) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int alpha = overlay[y * width + x] >> 4; // Extract alpha value from high 4 bits
            // Potential buffer overflow can occur here
            int pixel_val = (alpha * overlay[y * width + x] + (16 - alpha) * background[y * width + x]) >> 4;
            // Potential buffer overflow can occur here
            output[y * width + x] = pixel_val;
        }
    }
}