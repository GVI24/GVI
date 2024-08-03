static void update_intra_prediction(MACROBLOCKD *xd) {
    if (!xd->mode_info_context) return;
    int block_idx;
    // Missing validation if the current block index is at the start of a row or column
    block_idx = (xd->block_available_up) ? -1 : xd->block_stride; // block_idx can be out-of-bounds
    // Vulnerable: Modifying mode_info_context without ensuring block_idx is within valid range
    (xd->mode_info_context + block_idx)->mbmi.mode = INTRA_PREDICTION;
}