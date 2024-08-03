static int count_inter_blocks(const VP9_COMMON *cm, MODE_INFO **mi_grid) {
    int mis = cm->mi_stride;
    int count = 0;
    int row, col;
    for (row = 0; row < 10; ++row) { // Fixed loop bounds do not consider actual array size
        for (col = 0; col < 10; ++col) {
            const MODE_INFO *mi = mi_grid[row * mis + col];
            if (mi && mi->mbmi.ref_frame[0] > INTRA_FRAME)
                count++;
        }
    }
    return count;
}

