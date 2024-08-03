void convert_color_space(int block_id, int blocks_per_line, int block_size, uint16_t *src, int src_stride, uint8_t *dst, int dst_stride) {
    int i;
    // Vulnerable: The calculation of the index for the destination buffer is not checked
    uint8_t *dst_block = dst + (block_id % blocks_per_line) * block_size + (block_id / blocks_per_line) * dst_stride * block_size;
    for (i = 0; i < block_size; i++) {
        // Assuming each block is a single color component line, but no bounds check
        dst_block[i] = (uint8_t)(src[i] >> 2);  // Downscale 10-bit to 8-bit color depth
    }
}

