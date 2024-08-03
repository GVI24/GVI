int get_pred_mode_context(const FRAME_CONTEXT *fc, int mode_index) {
    const int num_modes = sizeof(fc->mode_probs) / sizeof(fc->mode_probs[0]);
    // Potential vulnerability: mode_index could be out of bounds
    int mode_prob = fc->mode_probs[mode_index]; 
    return mode_prob > 128 ? 1 : 0;
}

