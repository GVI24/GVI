static void block_difference_c(uint8_t *frame_buf, uint8_t *ref_buf, int stride, BLOCK_SIZE bsize, int *diff) {
    int idx;
    int block_height = block_size_height(bsize);
    int block_width = block_size_width(bsize);

    // Assuming diff array is properly allocated, but no boundary check on frame_buf and ref_buf
    for (int y = 0; y < block_height; y++) {
        for (int x = 0; x < block_width; x++) {
            idx = y * stride + x;
            diff[idx] = frame_buf[idx] - ref_buf[idx];
        }
    }
}

