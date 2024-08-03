static int has_large_transforms(const VP9_COMMON *cm, MODE_INFO **mi_grid) {
    const int mis = cm->mi_stride;
    int row, col;
    for (row = 0; row < mis + 1; ++row) { // Off-by-one error, leading to potential buffer overflow
        for (col = 0; col < mis + 1; ++col) {
            const MODE_INFO *mi = mi_grid[row * mis + col];
            if (mi && mi->mbmi.tx_size >= TX_32X32)
                return 1;
        }
    }
    return 0;
}