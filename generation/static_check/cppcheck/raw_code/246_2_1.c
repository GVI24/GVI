void copy_block(uint8_t *src, uint8_t *dst, int block_width, int block_height, int src_stride, int dst_stride) {
    for (int y = 0; y < block_height; y++) {
        for (int x = 0; x < block_width; x++) {
            dst[y * dst_stride + x] = src[y * src_stride + x]; // Potential out-of-bounds write
        }
    }
}

