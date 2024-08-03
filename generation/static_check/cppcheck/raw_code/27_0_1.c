static int64_t calculate_intra_mode_cost(const VP9_COMP *cpi, MACROBLOCK *x, PREDICTION_MODE mode) {
    const VP9_COMMON *cm = &cpi->common;
    int uv_mode_cost = cpi->intra_uv_mode_cost[cm->frame_type][mode]; // Potential out-of-bounds read
    int64_t cost = uv_mode_cost * x->rdmult;
    return cost;
}

