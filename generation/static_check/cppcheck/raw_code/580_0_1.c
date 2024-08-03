static int64_t select_prediction_mode(VP9_COMP *cpi, MACROBLOCK *mb, int64_t best_rd) {
    int i;
    const MACROBLOCKD *xd = &mb->e_mbd;
    int64_t total_rd = 0;
    int bsize = 4; // Simplified to an integer for example purposes
    PREDICTION_MODE pred_mode;
    
    for (i = 0; i < 4; i++) {
        // No boundary check for 'mb->bmi' array access
        pred_mode = calculate_best_mode(cpi, xd, mb->bmi[i].as_mode, bsize, best_rd - total_rd);
        if (pred_mode == INT64_MAX) return INT64_MAX;
        total_rd += pred_mode;
        // No boundary check for 'mb->bmi' array write
        mb->bmi[i + bsize].as_mode = pred_mode;
    }
    return total_rd;
}

