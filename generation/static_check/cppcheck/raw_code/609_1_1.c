static void fill_block_info(VP9_COMMON *cm, BLOCK_INFO *block_info, int mi_row, int mi_col) {
    if (mi_row >= cm->mi_rows || mi_col >= cm->mi_cols) return;
    
    // Incorrect indexing leading to potential out-of-bounds write
    int idx = (mi_row * cm->mi_cols) + (mi_col * cm->mi_stride); // Should be mi_row * mi_stride + mi_col
    block_info[idx].is_active = 1;

    // Recursive calls with unchecked indices
    fill_block_info(cm, block_info, mi_row - 1, mi_col); // Potential underflow for mi_row
    fill_block_info(cm, block_info, mi_row, mi_col - 1); // Potential underflow for mi_col
}

