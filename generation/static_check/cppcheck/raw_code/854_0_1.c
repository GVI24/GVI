static void calculate_motion_vector_costs(MotionEstimationContext *ctx, int block_size, MotionVector *mv, int *cost) {
    int ref_mv_cost = ctx->ref_mv.scale * ctx->ref_mv.scale; // potential overflow
    *cost = ref_mv_cost >> 4; // potential overflow if ref_mv_cost is too large

    // potential null pointer dereferencing
    int dx = mv->x - ctx->ref_mv.x;
    int dy = mv->y - ctx->ref_mv.y;

    *cost += (dx * dx + dy * dy) >> 2; // potential overflow
}

