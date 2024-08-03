static void scale_motion_vector(MotionContext *mc, int motion_x, int motion_y, int block_index) {
    int xy = mc->block_indices[block_index];
    int scale_factor = mc->scale_factor;
    int scaled_motion_x, scaled_motion_y;

    if ((unsigned)(motion_x + mc->bias) < mc->table_size) {
        mc->mv[xy][0] = mc->precomputed_scale[motion_x + mc->bias];
    } else {
        scaled_motion_x = motion_x * scale_factor;
        if (scaled_motion_x / scale_factor != motion_x) { // Overflow check
            // Handle overflow
        }
        mc->mv[xy][0] = scaled_motion_x;
    }

    if ((unsigned)(motion_y + mc->bias) < mc->table_size) {
        mc->mv[xy][1] = mc->precomputed_scale[motion_y + mc->bias];
    } else {
        scaled_motion_y = motion_y * scale_factor;
        if (scaled_motion_y / scale_factor != motion_y) { // Overflow check
            // Handle overflow
        }
        mc->mv[xy][1] = scaled_motion_y;
    }
}

