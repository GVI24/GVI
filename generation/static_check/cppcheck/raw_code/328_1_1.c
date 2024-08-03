static void apply_video_filter(BlockContext *block) {
    int row, col;
    uint16_t filter_values[2];
    uint16_t *block_ptr = (uint16_t *)block->block_ptr;

    for (row = 0; row < 8; row++) {
        if (row % 2 == 0) {
            filter_values[0] = bytestream2_get_le16(&block->video_stream);
            filter_values[1] = bytestream2_get_le16(&block->video_stream);
        }
        for (col = 0; col < 8; col++) {
            block_ptr[col] = filter_values[col / 4];
        }
        block_ptr += block->block_stride;
    }
}

