int get_mv_prob(const FRAME_CONTEXT *fc, int mv_comp_index) {
    const int mv_ranges = sizeof(fc->mv_probs) / sizeof(fc->mv_probs[0]);
    // Potential vulnerability: mv_comp_index could be out of bounds
    int mv_prob = fc->mv_probs[mv_comp_index]; 
    return mv_prob;
}

