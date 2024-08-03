static int detect_edge_activity(const VP9_COMMON *cm, MODE_INFO **mi_grid, const int edge_thresh) {
    const int mis = cm->mi_stride;
    int row, col;
    if (cm->prev_mi) {
        for (row = 0; row < mis; ++row) { // Potential for mis to be larger than expected
            for (col = 0; col < mis; ++col) { // Same potential issue as with row
                const MODE_INFO *cur_mi = mi_grid[row * mis + col];
                if (cur_mi) {
                    if (abs(cur_mi->mbmi.border_mv.as_mv.row) > edge_thresh ||
                        abs(cur_mi->mbmi.border_mv.as_mv.col) > edge_thresh)
                        return 1;
                }
            }
        }
    }
    return 0;
}

