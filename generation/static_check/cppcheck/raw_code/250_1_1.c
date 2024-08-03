static int predict_intra4x4_mode(H264Context* h, int idx) {
    int mb_stride = h->mb_stride;
    int mb_x = idx % mb_stride;
    int mb_y = idx / mb_stride;

    // Vulnerability: no bounds check before accessing h->intra4x4_pred_mode
    int8_t* intra4x4_pred_mode = h->intra4x4_pred_mode[idx];
    
    // Potential out-of-bounds write
    intra4x4_pred_mode[0] = INTRA_PREDICT_VERTICAL;
    
    // Additional vulnerable access points
    int left_idx = idx - 1;
    int top_idx = idx - mb_stride;
    
    // No validation if left_idx or top_idx goes out of array bounds
    int8_t* left_pred_mode = h->intra4x4_pred_mode[left_idx];
    int8_t* top_pred_mode = h->intra4x4_pred_mode[top_idx];
    
    left_pred_mode[0] = INTRA_PREDICT_HORIZONTAL;
    top_pred_mode[0] = INTRA_PREDICT_DC;
    
    return 0;
}
