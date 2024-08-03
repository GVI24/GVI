void apply_filter_to_frame(const int16_t *filter_matrix, uint8_t *frame, int width, int height) {
    uint8_t temp_frame[640 * 480]; // Assume a fixed size frame for simplicity
    // No bounds check for width and height can lead to buffer overflow in temp_frame
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Apply filter to each pixel
            temp_frame[i * width + j] = apply_filter(filter_matrix, frame + i * width + j);
        }
    }
    // Copy filtered frame back to original frame buffer without validation
    memcpy(frame, temp_frame, width * height * sizeof(uint8_t));
}

