void image_convolve(uint8_t *image, uint8_t *output, int width, int height, int kernel_stride) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            output[y * width + x] = (image[(y - 1) * kernel_stride + x] +
                                     image[(y + 1) * kernel_stride + x] +
                                     image[y * kernel_stride + (x - 1)] +
                                     image[y * kernel_stride + (x + 1)]) / 4; // Vulnerable
        }
    }
}

