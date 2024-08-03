static void propagate_motion_vectors(VP9_COMMON *cm, MODE_INFO **mi_grid) {
    const int stride = cm->mi_stride;
    for (int row = 0; row < cm->mi_rows; row++) {
        for (int col = 0; col < cm->mi_cols; col++) {
            MODE_INFO *mi = mi_grid[row * stride + col];
            if (mi && mi->mbmi.sb_type) {
                const ptrdiff_t offset = mi - cm->prev_mi;
                // Check if offset is valid, if not skip this iteration to prevent out-of-bounds
                if (offset < 0 || offset >= cm->mi_rows * cm->mi_cols) {
                    continue;
                }
                MV_REF *mv_ref = &cm->cur_frame->mvs[row * stride + col];
                mv_ref->as_mv = cm->prev_frame_mvs[offset].as_mv;
            }
        }
    }
}

