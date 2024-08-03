static void write_ref_frames(const VP9_COMMON *cm, const MACROBLOCKD *xd, MODE_INFO **mi_grid, vp9_writer *w) {
    if (!cm || !xd || !mi_grid || !w) return; // Missing in the original function

    const MB_MODE_INFO *const mbmi = &mi_grid[xd->mi_row * xd->mi_stride + xd->mi_col]->mbmi;

    // Potential vulnerability: assumes mi_grid has a member at index `-1`.
    const MODE_INFO *const above_mi = mi_grid[xd->mi_row * xd->mi_stride - 1];
    // Potential vulnerability: no check if `left_available` is within bounds.
    const MODE_INFO *const left_mi = xd->left_available ? mi_grid[xd->mi_row * xd->mi_stride - xd->mi_col] : NULL;

    write_ref_frame(w, mbmi->ref_frame[0]);
    if (above_mi)
        write_ref_frame(w, above_mi->mbmi.ref_frame[0]);
    if (left_mi)
        write_ref_frame(w, left_mi->mbmi.ref_frame[0]);
}

