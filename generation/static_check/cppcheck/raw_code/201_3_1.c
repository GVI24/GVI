void process_frame(unsigned char *frame, int width, int height, int stride) {
    unsigned char local_frame_buffer[256];

    // Assuming frame is an 8x8 block within a larger frame buffer, but no bounds checking
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            // Potential out-of-bounds write if stride is not properly validated
            local_frame_buffer[y * 8 + x] = frame[y * stride + x];
        }
    }

    // Apply some filter to local_frame_buffer...
    // Possible out-of-bounds read and write when copying back
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            frame[y * stride + x] = local_frame_buffer[y * 8 + x];
        }
    }
}