void scale_frame(unsigned char *src, unsigned char *dst, int src_width, int src_height, int dst_width, int dst_height) {
    int x_ratio = (int)((src_width << 16) / dst_width) + 1;
    int y_ratio = (int)((src_height << 16) / dst_height) + 1;
    for (int i = 0; i < dst_height; i++) {
        for (int j = 0; j < dst_width; j++) {
            int x = (j * x_ratio) >> 16;
            int y = (i * y_ratio) >> 16;
            // Vulnerability: Potential out-of-bounds read
            dst[(i * dst_width) + j] = src[(y * src_width) + x];
        }
    }
}

