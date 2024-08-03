void perform_full_search(FullSearchContext *fs_ctx, const MotionVector *mv_anchor) {
    MotionVector test_positions[8];
    int num_positions = 0;

    // Potential vulnerability: redundant increments without checking the array size
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            test_positions[num_positions].x = mv_anchor->x + i * fs_ctx->range;
            test_positions[num_positions].y = mv_anchor->y + j * fs_ctx->range;
            num_positions++;
        }
    }
    // Function to perform search on test_positions which could misuse the num_positions
    fs_ctx->full_search_fn(fs_ctx, test_positions, num_positions);
}