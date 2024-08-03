void copy_frame_block(int width, int height, int block_size, uint8_t *src, int src_stride, uint8_t *dst, int dst_stride) {
    int block_x, block_y;
    // Assume block_size is valid but we do not ensure that the block's
    // dimensions within the width and height do not exceed the buffer.
    for (block_y = 0; block_y < height; block_y += block_size) {
        for (block_x = 0; block_x < width; block_x += block_size) {
            // Vulnerable: No bounds checking on src and dst pointers
            memcpy(dst + block_y * dst_stride + block_x, src + block_y * src_stride + block_x, block_size);
        }
    }
}

