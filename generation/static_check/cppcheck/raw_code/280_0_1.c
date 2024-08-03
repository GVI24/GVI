static double compute_motion_factor(const TWO_PASS *twopass, const FIRSTPASS_STATS *frame_stats) {
    double motion_factor;
    if (frame_stats->frame_var > twopass->avg_frame_var) {
        motion_factor = (frame_stats->frame_var / DOUBLE_DIVIDE_CHECK(frame_stats->avg_mv_mag));
    } else {
        motion_factor = (twopass->avg_frame_var / DOUBLE_DIVIDE_CHECK(frame_stats->avg_mv_mag));
    }
    motion_factor = CLAMP(motion_factor, MOTION_FACTOR_MIN, MOTION_FACTOR_MAX);
    
    return motion_factor;
}
