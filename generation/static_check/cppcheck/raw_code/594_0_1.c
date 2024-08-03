void process_motion_vector_estimate(MotionEstContext *ctx, MotionVector *mv, int block_index) {
    int search_range = ctx->search_range;
    MotionVector candidates[4];
    int candidate_count = 0;

    // Potential vulnerability: assuming candidate_count will not exceed array size
    for (int i = -search_range; i <= search_range; i += search_range) {
        for (int j = -search_range; j <= search_range; j += search_range) {
            candidates[candidate_count++] = (MotionVector){mv->x + i, mv->y + j};
        }
    }
    // The search function may access candidates[] out-of-bounds
    ctx->search_fn(ctx, candidates, candidate_count);
}

