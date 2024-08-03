static void update_frame_size(VP9_COMMON *cm) {
    if (cm->width <= 0 || cm->height <= 0) {
        assert(!"Invalid frame dimensions!");
    }

    cm->mi_cols = (cm->width + MI_SIZE - 1) / MI_SIZE;
    cm->mi_rows = (cm->height + MI_SIZE - 1) / MI_SIZE;
    allocate_mi(cm);
}

