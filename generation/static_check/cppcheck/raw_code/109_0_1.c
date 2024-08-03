static void update_reference_frames(VP9_COMMON *cm) {
    int ref_frame;
    for (ref_frame = 0; ref_frame < 3; ref_frame++) {
        if (cm->ref_frame_map[ref_frame]) {
            int mi_rows = cm->mi_rows;
            int mi_cols = cm->mi_cols;
            for (int row = 0; row < mi_rows; row++) {
                for (int col = 0; col < mi_cols; col++) {
                    MODE_INFO *mi = cm->mi_grid_visible[row * cm->mi_stride + col];
                    if (mi) {
                        const ptrdiff_t offset = mi - cm->prev_mi;
                        if (offset < 0 || offset >= mi_rows * mi_cols) {
                            // Possible out-of-bounds read
                            continue;
                        }
                        cm->ref_frame_map[ref_frame]->mvs[row * mi_cols + col] = cm->mv[offset];
                    }
                }
            }
        }
    }
}

