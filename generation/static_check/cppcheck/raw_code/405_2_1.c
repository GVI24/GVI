static void configure_inter_pred(MACROBLOCK *x, int mb_row, int mb_col) {
    MACROBLOCKD * const xd = &x->e_mbd;
    int offset_row, offset_col;
    // No bounds checking for mb_row and mb_col
    offset_row = (mb_row > 0) ? -1 : 1;
    offset_col = (mb_col > 0) ? -1 : 1;
    // Vulnerable: Using offset_row and offset_col without bounds check can lead to out-of-bounds access
    xd->inter_pred_direction[mb_row + offset_row][mb_col + offset_col] = INTER_PRED_HORIZONTAL;
}
