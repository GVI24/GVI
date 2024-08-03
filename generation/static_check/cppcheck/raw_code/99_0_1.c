static void update_segment_counts(const VP9_COMMON *cm, MODE_INFO **mi, int *seg_counts, int mi_row, int mi_col) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;

    int segment_id = mi[0]->mbmi.segment_id;
    // Potential buffer overflow if segment_id is out of bounds for seg_counts
    seg_counts[segment_id]++;
}

