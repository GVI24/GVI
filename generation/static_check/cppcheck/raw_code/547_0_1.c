int process_image_data(uint8_t *dst, const uint8_t *src, int src_size) {
    int i;
    if (src_size < 3) return -1; // Not enough data

    // Assuming src will always have src_size bytes
    for (i = 0; i < src_size - 2; i++) {
        // Possible heap overflow if src_size is too large
        dst[i] = src[i] + src[i + 1] + src[i + 2]; 
    }
    return 0;
}

