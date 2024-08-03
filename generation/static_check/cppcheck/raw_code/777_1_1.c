void allocate_frame(int width, int height) {
    // Potential integer overflow if width * height is too large
    size_t buffer_size = width * height; 
    uint8_t *frame_buffer = (uint8_t *)malloc(buffer_size);
    if (frame_buffer == NULL) {
        // Handle allocation error
    } else {
        memset(frame_buffer, 0, buffer_size); // If overflow occurs, buffer_size would be smaller than expected
    }
}

