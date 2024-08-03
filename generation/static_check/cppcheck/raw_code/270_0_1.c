void horizontal_loop_filter(uint8_t *frame_data, int width, const uint8_t *threshold) {
    int i;
    uint8_t temp_buffer[64]; // Fixed buffer size
    for (i = 0; i < width + 4; i++) { // Potential for off-by-one error
        temp_buffer[i] = frame_data[i] - threshold[i % 3]; // Unchecked access to frame_data
    }
    // Processing and updating the original frame_data buffer
    for (i = 0; i < width; i++) {
        frame_data[i] = temp_buffer[i]; // Writing back to frame_data without boundary checks
    }
}