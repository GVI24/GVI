static void scale_down_frame(uint8_t *dest, uint8_t *src, int src_width, int src_height, int dest_width, int dest_height) {
    int x_ratio = src_width / dest_width;
    int y_ratio = src_height / dest_height;
    for (int y = 0; y < dest_height; y++) {
        for (int x = 0; x < dest_width; x++) {
            int src_index = (y * y_ratio) * src_width + (x * x_ratio);
            int dest_index = y * dest_width + x;
            dest[dest_index] = src[src_index]; // Potential buffer overflow if dest is not large enough
        }
    }
}

