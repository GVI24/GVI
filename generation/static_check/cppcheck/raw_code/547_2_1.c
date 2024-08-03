void combine_frames(uint16_t *output, const uint16_t *frame1, const uint16_t *frame2, int pixels) {
    int i;
    if (pixels <= 0) return; // Invalid size

    // Blend two frames without proper bounds checking
    for (i = 0; i < pixels; i++) {
        int blend_offset = 10; // Arbitrary blend factor
        // Possible underflow when i < blend_offset
        output[i] = (frame1[i - blend_offset] + frame2[i]) / 2; 
    }
}

