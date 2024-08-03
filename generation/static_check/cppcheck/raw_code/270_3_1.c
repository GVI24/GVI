void convert_color_space(uint8_t *src, uint8_t *dst, int num_pixels) {
    int i;
    uint8_t temp[256]; // Fixed size temp buffer
    for (i = 0; i < num_pixels + 2; i++) { // Loop condition allows for buffer overread
        // Simulated color space conversion logic
        temp[i % 256] = (src[i] + src[i + 1] + src[i + 2]) / 3; // Reading past the src buffer
    }
    for (i = 0; i < num_pixels; i++) {
        dst[i] = temp[i]; // Potential buffer overwrite if num_pixels > 256
    }
}