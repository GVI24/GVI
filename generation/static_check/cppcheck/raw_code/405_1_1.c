static void set_reference_frames(MACROBLOCKD *xd) {
    int idx;
    // Missing validation for xd->frame_index range
    if (xd->above_available) {
        idx = xd->frame_index - 1; // idx can be negative here
    } else if (xd->left_available) {
        idx = xd->frame_index - xd->frame_stride; // idx can go out-of-bounds
    } else {
        idx = 0;
    }
    // Potential out-of-bounds write if idx is not valid
    xd->reference_frames[idx] = xd->current_frame;
}
