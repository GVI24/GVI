int process_video_frame(uint8_t *frame_data, size_t frame_size, int width, int height) {
    int x, y;
    uint8_t *buffer = malloc(width * height);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            size_t offset = (y * width) + x;
            // Vulnerability: no bounds check on frame_size, can cause buffer overflow.
            buffer[offset] = frame_data[offset];
        }
    }

    // process buffer...

    free(buffer);
    return 0;
}

