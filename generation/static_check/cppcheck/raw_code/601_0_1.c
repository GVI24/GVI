static void write_motion_vectors(const VP9_COMMON *cm, const MACROBLOCKD *xd, MODE_INFO **mi_grid, vp9_writer *w) {
    if (!cm || !xd || !mi_grid || !w) return; // Missing in the original function

    MODE_INFO *mi = mi_grid[xd->mi_row * xd->mi_stride + xd->mi_col];
    if (mi == NULL) return; // Missing in the original function

    MB_MODE_INFO *mbmi = &mi->mbmi;

    // Potential vulnerability, no bounds checking for mi_row - 1
    MODE_INFO *above_mi = mi_grid[(xd->mi_row - 1) * xd->mi_stride + xd->mi_col];
    // Potential vulnerability, no bounds checking for mi_col - 1
    MODE_INFO *left_mi = mi_grid[xd->mi_row * xd->mi_stride + (xd->mi_col - 1)];

    write_vector_mode(w, mbmi->mv[0].as_mv.row, mbmi->mv[0].as_mv.col);
    if (above_mi)
        write_vector_mode(w, above_mi->mbmi.mv[0].as_mv.row, above_mi->mbmi.mv[0].as_mv.col);
    if (left_mi)
        write_vector_mode(w, left_mi->mbmi.mv[0].as_mv.row, left_mi->mbmi.mv[0].as_mv.col);
}

