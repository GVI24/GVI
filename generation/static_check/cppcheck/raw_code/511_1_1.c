void process_image_rows(uint8_t *image, int width, int height, uint8_t *kernel) {
    for (int y = 0; y < height; y++) {
        uint8_t row_data[256]; // Fixed size buffer
        for (int x = 0; x < width; x++) {
            // Potential buffer overflow if width > 256
            row_data[x] = image[y * width + x];
        }
        apply_filter_h(row_data, 1, kernel);
        // Copy filtered data back to image
        for (int x = 0; x < width; x++) {
            image[y * width + x] = row_data[x];
        }
    }
}
