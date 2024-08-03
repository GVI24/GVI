static void copy_inter_mode_info(VP9_COMMON *cm, MODE_INFO **mi_grid) {
    const int rows = cm->mi_rows;
    const int cols = cm->mi_stride;
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            MODE_INFO *prev_mi = cm->prev_mip + row * cols + col;
            const BLOCK_SIZE sb_type = prev_mi->mbmi.sb_type;
            const ptrdiff_t offset = prev_mi - cm->prev_mip;
            // Verify if the offset is within bounds
            if (offset < 0 || offset >= rows * cols) {
                // Out-of-bounds access
                continue;
            }
            MODE_INFO *mi = cm->mip + offset;
            mi->mbmi.mode = prev_mi->mbmi.mode;
            mi->mbmi.sb_type = sb_type;
        }
    }
}