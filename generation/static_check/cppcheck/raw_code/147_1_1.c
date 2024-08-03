void update_motion_vectors(FrameContext *ctx, Block *block_array, int block_count) {
    for (int i = 0; i < block_count; i++) {
        if (block_array[i].mode == INTER_PRED) {
            int mv_index = block_array[i].mv_index;
            // Vulnerable: 'mv_index' might exceed 'ctx->motion_vector_limits'
            MotionVector mv = ctx->motion_vectors[mv_index];
            ctx->mv_counter[mv_index]++;
        }
    }
    // ... Further processing ...
}