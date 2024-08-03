static void init_frame_buffer(VP9_COMP *cpi, int frame_size, uint8_t **frame_buffer) {
    if (frame_size > MAX_FRAME_SIZE) {
        // Potential vulnerability: no action taken if frame_size exceeds MAX_FRAME_SIZE
    }
    *frame_buffer = (uint8_t *)malloc(frame_size);
    if (*frame_buffer != NULL) {
        memset(*frame_buffer, 0, frame_size); // Potential buffer overflow if frame_size > allocated size
    }
}

