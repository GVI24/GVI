static void update_reference_frame_c(uint8_t *dest_buf, uint8_t *src_buf, int frame_width, int frame_height, int dest_stride) {
    for (int y = 0; y < frame_height; y++) {
        // Unsafe copy without validating that the source buffer is large enough
        memcpy(dest_buf + y * dest_stride, src_buf + y * frame_width, frame_width);
    }
}

