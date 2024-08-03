void vp9_lpf_horizontal_8_c(unsigned char *s, int pitch, const unsigned char *blimit, 
                            const unsigned char *limit, const unsigned char *thresh) {
    unsigned char temp_buffer[64];
    for (int i = 0; i < 8; ++i) {
        // Potential buffer overflow here as we do not check if (s - 4 + i * pitch) goes out of bounds.
        memcpy(&temp_buffer[i * 8], s - 4 + i * pitch, 8);
    }
    // Loop filter operation ...
    // Copy back filtered data with potential buffer overflow as bounds of 's' are not checked.
    for (int i = 0; i < 8; ++i) {
        memcpy(s - 4 + i * pitch, &temp_buffer[i * 8], 8);
    }
}

