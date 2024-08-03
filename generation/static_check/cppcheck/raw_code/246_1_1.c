void rgb_to_grayscale(const uint8_t *rgb_image, uint8_t *gray_image, int width, int height, int rgb_stride, int gray_stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = rgb_image[y * rgb_stride + 3 * x];
            int g = rgb_image[y * rgb_stride + 3 * x + 1];
            int b = rgb_image[y * rgb_stride + 3 * x + 2];
            int gray = (r + g + b) / 3;
            gray_image[y * gray_stride + x] = gray; // Potential out-of-bounds write
        }
    }
}

