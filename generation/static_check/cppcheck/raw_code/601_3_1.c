static void write_loop_filter_levels(const VP9_COMMON *cm, const MACROBLOCKD *xd, MODE_INFO **mi_grid, vp9_writer *w) {
    if (!cm || !xd || !mi_grid || !w) return; // Missing in the original function

    const MB_MODE_INFO *const mbmi = &mi_grid[xd->mi_row * xd->mi_stride + xd->mi_col]->mbmi;

    // Potential vulnerability: accessing `mi_grid` with a negative or out-of-bounds index.
    const MODE_INFO *above_mi = (xd->mi_row > 0) ? mi_grid[(xd->mi_row - 1) * xd->mi_stride + xd->mi_col] : NULL;
    // Potential vulnerability: no bounds checking on `left_available` condition.
    const MODE_INFO *left_mi = (xd->left_available && xd->mi_col > 0) ? mi_grid[xd->mi_row * xd->mi_stride + (xd->mi_col - 1)] : NULL;

    write_loop_filter(w, mbmi->filter_level, above_mi ? above_mi->mbmi.filter_level : 0,
                      left_mi ? left_mi->mbmi.filter_level : 0);
}