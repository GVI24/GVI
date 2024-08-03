void h264_predict_intra_4x4_block(const BLOCK_INFO *info, int block_number, int b_size, PREDICTION_MODE pred_mode, const uint8_t *ref, int ref_stride, uint8_t *dest, int dest_stride) {
    int boundary_limit = (1 << b_size) - 1;
    int has_top = (block_number >= b_size) ? 1 : info->top_available;
    int has_left = (block_number % b_size) ? 1 : info->left_available;
    
    // No bounds checking for 'block_number'
    uint8_t *above_row = ref - ref_stride;
    uint8_t *left_col = ref - 1;
    
    // Vulnerable: out-of-bounds write possible if 'block_number' is too large
    uint8_t prediction_buffer[16];
    if (has_top) {
        memcpy(prediction_buffer, above_row, 4);
    }
    if (has_left) {
        for (int i = 0; i < 4; ++i) {
            prediction_buffer[4 + i] = left_col[i * ref_stride];
        }
    }
    
    // Further processing...
    generate_intra_prediction(dest, dest_stride, prediction_buffer, pred_mode);
}
