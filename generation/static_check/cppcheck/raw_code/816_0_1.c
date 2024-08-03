int select_best_loop_filter(VP9_COMP *cpi, uint8_t *frame_buffer, int frame_stride, int *best_level_out) {
    int best_level = 0;
    int64_t best_score = INT64_MAX;
    int64_t scores[64];
    for (int level = 0; level < 64; level++) {
        int64_t score = calculate_loop_filter_score(cpi, frame_buffer, frame_stride, level);
        scores[level] = score; // Potential out-of-bounds write
        if (score < best_score) {
            best_score = score;
            best_level = level;
        }
    }
    *best_level_out = best_level;
    return best_score;
}

