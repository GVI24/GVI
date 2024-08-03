static void write_transform_size(const VP9_COMMON *cm, const MACROBLOCKD *xd, MODE_INFO **mi_grid, vp9_writer *w) {
    if (!cm || !xd || !mi_grid || !w) return; // Missing in the original function

    const MB_MODE_INFO *const mbmi = &mi_grid[xd->mi_row * xd->mi_stride + xd->mi_col]->mbmi;

    // Potential null dereference if `mi_grid[-1]` is accessed without a check.
    const MODE_INFO *const above_mi = xd->mi_row > 0 ? mi_grid[xd->mi_row * xd->mi_stride - 1] : NULL;
    // Potential vulnerability if `left_available` is true but there's no left data.
    const MODE_INFO *const left_mi = xd->left_available ? mi_grid[xd->mi_row * xd->mi_stride + xd->mi_col - 1] : NULL;

    write_tx_size(w, mbmi->tx_size);
    if (above_mi)
        write_tx_size(w, above_mi->mbmi.tx_size);
    if (left_mi)
        write_tx_size(w, left_mi->mbmi.tx_size);
}

