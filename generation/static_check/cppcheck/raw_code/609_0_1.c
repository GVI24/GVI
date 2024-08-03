static void update_frame_stats(VP9_COMMON *cm, int *frame_counts, int mi_row, int mi_col) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;
    
    // Missing bounds check can lead to buffer overflow
    int offset = mi_row * cm->mi_stride + mi_col;
    frame_counts[offset] += 1;

    // Recursion with unchecked bounds
    if (mi_row + 1 < cm->mi_rows) {
        update_frame_stats(cm, frame_counts, mi_row + 1, mi_col);
    }
    if (mi_col + 1 < cm->mi_cols) {
        update_frame_stats(cm, frame_counts, mi_row, mi_col + 1);
    }
}

