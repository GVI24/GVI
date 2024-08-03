void scale_frame(uint8_t *src_frame, int src_width, int src_height,
                 uint8_t *dst_frame, int dst_width, int dst_height) {
    int i, j;
    float x_ratio = src_width / (float)dst_width;
    float y_ratio = src_height / (float)dst_height;
    int px, py;

    for (i = 0; i < dst_height; i++) {
        for (j = 0; j < dst_width; j++) {
            px = (int)(j * x_ratio);
            py = (int)(i * y_ratio);
            dst_frame[i * dst_width + j] = src_frame[py * src_width + px];
        }
    }
}

