static void blend_frames(uint8_t* base_frame, uint8_t* overlay_frame, int width, int height, uint8_t* blended_output) {
    int i;
    for (i = 0; i < width * height; i++) {
        blended_output[i] = (base_frame[i] / 2) + (overlay_frame[i] / 2); // Potential buffer overflow
    }
}

