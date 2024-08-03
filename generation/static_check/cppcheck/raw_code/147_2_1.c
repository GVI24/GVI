void count_frame_block_mvs(BlockData *block_data, int rows, int cols) {
    MotionCount *mc = block_data->motion_count;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c += 2) {
            int block_index = r * cols + c;
            // Vulnerable: Assumption that 'cols' is always even, might cause 'block_index' to be out-of-bounds
            if (block_data->blocks[block_index].type == MOVING) {
                increment_mv_count(mc, block_data->blocks[block_index].mv);
            }
        }
    }
    // ... Additional logic ...
}