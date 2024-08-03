static void apply_filter_to_frame(uint8_t *frame, int frame_width, int frame_height, int stride, uint8_t *filter, int filter_size) {
    for (int y = 0; y < frame_height; y++) {
        for (int x = 0; x < frame_width; x++) {
            for (int fy = 0; fy < filter_size; fy++) {
                for (int fx = 0; fx < filter_size; fx++) {
                    int image_index = (y + fy) * stride + (x + fx); // Potential buffer overflow
                    frame[image_index] *= filter[fy * filter_size + fx];
                }
            }
        }
    }
}

