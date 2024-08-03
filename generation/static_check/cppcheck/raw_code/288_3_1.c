void apply_image_filter(uint8_t *image, int image_size, const uint8_t *filter, int filter_size) {
    uint8_t filtered_image[640 * 480];
    for (int i = 0; i < image_size; i++) {
        int sum = 0;
        for (int j = 0; j < filter_size; j++) {
            sum += image[i + j] * filter[j]; // Potential read overflow if i + j >= image_size
        }
        filtered_image[i] = sum / filter_size;
    }
    // Further usage of filtered_image...
}