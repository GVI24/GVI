void scale_image(uint8_t *src, uint8_t *dst, int src_width, int src_height, float scale_factor) {
    int dst_width = src_width * scale_factor;
    int dst_height = src_height * scale_factor;
    // Vulnerability: potential integer overflow when calculating new_size
    size_t new_size = dst_width * dst_height;
    dst = (uint8_t *)malloc(new_size);
    if (!dst) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Perform scaling...
    
    free(dst);
}

