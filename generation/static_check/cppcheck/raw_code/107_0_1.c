void copy_video_block(uint8_t *dest, uint8_t *src, int block_size, int num_blocks) {
    for (int i = 0; i < num_blocks; ++i) {
        memcpy(dest + i * block_size, src + i * block_size, block_size); // Potential buffer overflow
    }
}