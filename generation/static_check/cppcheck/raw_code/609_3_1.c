static void calculate_segment_diff(VP9_COMMON *cm, int *segment_diffs, int mi_row, int mi_col, int depth) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;
    
    // Base case missing for recursion could lead to stack overflow
    int index = mi_row * cm->mi_stride + mi_col;
    segment_diffs[index] = depth; // Some arbitrary calculation for segment_diffs

    // Recursive calls increasing depth without limit
    calculate_segment_diff(cm, segment_diffs, mi_row + 1, mi_col, depth + 1);
    calculate_segment_diff(cm, segment_diffs, mi_row, mi_col + 1, depth + 1);
}