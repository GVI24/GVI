static inline int motion_comp_average(MpegEncContext *s, int x, int y) {
    int motion_val, top_motion_val, left_motion_val;
    int *motion_vals = s->motion_val + x + y * s->mb_width;

    // Potential out-of-bounds access if x or y are 0
    top_motion_val = motion_vals[-s->mb_width];
    left_motion_val = motion_vals[-1];

    // Vulnerability: No checks for boundary conditions
    motion_val = (top_motion_val + left_motion_val) / 2;
    
    return motion_val;
}

