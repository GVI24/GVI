void vertical_filter(uint8_t *image_data, int height, int line_stride) {
    uint8_t filter_buffer[256];
    for (int y = 0; y <= height; y++) { // Loop may exceed the height
        for (int x = 0; x < line_stride; x++) {
            filter_buffer[y * line_stride + x] = image_data[y * line_stride + x]; // Overflows filter_buffer
        }
    }
    // Some filtering logic (omitted for brevity)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < line_stride; x++) {
            image_data[y * line_stride + x] = filter_buffer[y * line_stride + x]; // Reading back from potentially corrupted buffer
        }
    }
}