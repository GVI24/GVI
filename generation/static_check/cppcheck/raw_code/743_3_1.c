static int compute_sad_c(uint8_t *cur_frame, uint8_t *ref_frame, int stride, BLOCK_SIZE bsize) {
    int sad = 0;
    int block_height = block_size_height(bsize);
    int block_width = block_size_width(bsize);

    for (int y = 0; y < block_height; y++) {
        for (int x = 0; x < block_width; x++) {
            // Potential overflow if cur_frame or ref_frame buffers are not large enough for the block size
            sad += abs(cur_frame[y * stride + x] - ref_frame[y * stride + x]);
        }
    }
    return sad;
}