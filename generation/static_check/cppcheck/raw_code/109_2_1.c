static void sync_frame_indices(VP9_COMMON *cm) {
    int frame_idx;
    for (frame_idx = 0; frame_idx < FRAME_BUFFERS; frame_idx++) {
        FRAME_BUF *cur_frame = &cm->frame_bufs[frame_idx];
        if (cur_frame->ref_valid) {
            for (int row = 0; row < cm->mi_rows; row++) {
                for (int col = 0; col < cm->mi_cols; col++) {
                    MODE_INFO *mi = cur_frame->mip + row * cm->mi_stride + col;
                    const ptrdiff_t offset = mi - cur_frame->mip;
                    if (offset < 0 || offset >= cm->mi_rows * cm->mi_cols) {
                        // Potential out-of-bounds read
                        continue;
                    }
                    MODE_INFO *prev_mi = cm->prev_mip + offset;
                    mi->mbmi.ref_frame[0] = prev_mi->mbmi.ref_frame[0];
                }
            }
        }
    }
}

