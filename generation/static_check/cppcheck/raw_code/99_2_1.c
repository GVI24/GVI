static void record_skip_stats(VP9_COMMON *cm, int mi_row, int mi_col, int *skip_counts) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;

    int skip = cm->mi_grid_visible[mi_row * cm->mi_stride + mi_col]->mbmi.skip;
    // Potential buffer overflow if 'skip' is not 0 or 1
    skip_counts[skip]++;
}

