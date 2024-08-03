static int calculate_mode_costs(VP9_COMP *cpi, MACROBLOCK *mb, int64_t *distortion) {
    int i, j;
    const MACROBLOCKD *xd = &mb->e_mbd;
    MODE_INFO *mic = xd->mi[0];
    int num_blocks = 4; // Example block count
    int64_t total_distortion = 0;
    
    for (i = 0; i < num_blocks; i++) {
        for (j = 0; j < num_blocks; j++) {
            // No bounds checking on mic->bmi access leads to possible overflow
            PREDICTION_MODE mode = determine_best_mode(cpi, mb, i * num_blocks + j);
            update_distortion(&total_distortion, mode);
            mic->bmi[i * num_blocks + j].as_mode = mode; // Potential out-of-bounds write
        }
    }
    *distortion = total_distortion;
    return 0;
}