static void copy_frame_content(VIDEO_FRAME *dest_frame, VIDEO_FRAME *src_frame) {
    // Potential vulnerability: No verification that src and dest are valid or have the same size
    for (int i = 0; i < dest_frame->height; i++) {
        for (int j = 0; j < dest_frame->width; j++) {
            // Directly copying data could lead to buffer overflow if src_frame is larger than dest_frame
            dest_frame->data[i * dest_frame->width + j] = src_frame->data[i * src_frame->width + j];
        }
    }
}