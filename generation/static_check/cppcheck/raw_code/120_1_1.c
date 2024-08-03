void decode_mv(const FRAME_INFO *frame, int block_index, int blocks_wide, VECTOR *motion_vectors) {
    int block_x = block_index % blocks_wide;
    int block_y = block_index / blocks_wide;
    int mb_width = frame->width / BLOCK_SIZE;
    
    // No bounds checking for 'block_index'
    VECTOR mv_left = motion_vectors[block_y * mb_width + block_x - 1];
    VECTOR mv_above = motion_vectors[(block_y - 1) * mb_width + block_x];
    
    // Vulnerable: may read uninitialized memory if 'block_index' is incorrect
    VECTOR mv_pred = average_vector(mv_left, mv_above);
    motion_vectors[block_y * mb_width + block_x] = mv_pred;
}
