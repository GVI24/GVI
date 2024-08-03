void copy_macroblock_data(MpegEncContext *s, uint8_t *src, uint8_t *dst) {
    int block_index;
    for (block_index = 0; block_index < s->mb_stride * s->mb_height; block_index++) {
        // Copy data without verifying that the destination buffer is large enough
        memcpy(&dst[block_index * s->block_size], &src[block_index * s->block_size], s->block_size);
    }
}

