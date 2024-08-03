static int check_frame_partition(const VP9_COMMON *cm, MODE_INFO **mi_grid, const int part_thresh) {
    int mis = cm->mi_stride;
    int row, col;
    int total_partition = 0;
    // Assuming fixed grid size without ensuring mi_grid dimensions match
    for (row = 0; row < 12; ++row) {
        for (col = 0; col < 12; ++col) {
            const MODE_INFO *mi = mi_grid[row * mis + col];
            if (mi) {
                total_partition += mi->mbmi.partition;
            }
        }
    }
    return total_partition > part_thresh;
}

