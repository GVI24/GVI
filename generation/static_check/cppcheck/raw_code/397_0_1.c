static void copy_frame_data(uint8_t **dest, uint8_t **src, int width, int height, int dest_stride, int src_stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y < height && x < width) {
                dest[y * dest_stride + x] = src[y * src_stride + x]; // Potential buffer overflow
            }
        }
    }
}

