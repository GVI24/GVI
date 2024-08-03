void process_sub_blocks(VideoFrame *frame, int block_size) {
    BlockInfo *blocks = frame->block_info;
    int sub_block_total = block_size * block_size;
    for (int y = 0; y < block_size; y++) {
        for (int x = 0; x < block_size; x++) {
            int index = y * block_size + x;
            if (blocks[index].motion_type == INTRAPRED) {
                // Vulnerable: No bounds check on 'blocks' array
                update_motion_vector(&blocks[index].motion_vector, frame->mv_counts);
            }
        }
    }
    // ... Other processing ...
}