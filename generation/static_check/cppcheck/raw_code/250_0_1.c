static int check_motion_vector_range(H264Context* h, int mvx, int mvy) {
    int mb_xy = h->mb_xy;
    int mb_width = h->mb_width;
    int mb_height = h->mb_height;
    int mb_stride = h->mb_stride;
    
    // Vulnerability: no bounds check before accessing h->motion_val
    int16_t (*motion_val)[2] = h->motion_val[mb_xy];
    
    // Potential out-of-bounds write if mvx or mvy is out of expected range
    motion_val[0][0] = mvx;
    motion_val[0][1] = mvy;
    
    // Additional vulnerable access points
    int left_xy = mb_xy - 1;
    int top_xy = mb_xy - mb_stride;
    
    // No validation if left_xy or top_xy goes negative
    int16_t (*left_val)[2] = h->motion_val[left_xy];
    int16_t (*top_val)[2] = h->motion_val[top_xy];
    
    left_val[0][0] = mvx - 1;
    left_val[0][1] = mvy;
    top_val[0][0] = mvx;
    top_val[0][1] = mvy - 1;
    
    return 0;
}
