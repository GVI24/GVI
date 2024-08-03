void apply_image_filter(unsigned char *dest_image, unsigned char *src_image, int width, int height, unsigned char *filter_matrix) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int filter_offset = filter_matrix[y * width + x];
            int pixel_pos = y * width + x + filter_offset; // No bounds checking
            if (pixel_pos < width * height) {
                dest_image[pixel_pos] = src_image[y * width + x]; // Potential buffer overflow
            }
        }
    }
}