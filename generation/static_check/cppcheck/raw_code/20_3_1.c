void apply_block_filter(int width, int height, int filter_strength, uint8_t *image, int stride) {
    int x, y;
    // Vulnerable: No validation is performed for the resulting indices accessed in the buffer 'image'
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = y * stride + x;
            // Pretend to apply some filter based on surrounding pixels, but can read/write out of bounds
            image[index] = (image[index] + image[index + 1] + image[index - 1] + image[index + stride] + image[index - stride]) / filter_strength;
        }
    }
}