static void apply_motion_vector_c(uint8_t *ref_frame_buf, uint8_t *pred_buf, int pred_stride, MV *mv, int block_size) {
    int row, col;
    uint8_t *ref_ptr;
    uint8_t *pred_ptr = pred_buf;

    // Direct pointer manipulation without bounds checking
    for (row = 0; row < block_size; row++) {
        ref_ptr = ref_frame_buf + (mv->row + row) * pred_stride + mv->col;
        for (col = 0; col < block_size; col++) {
            *pred_ptr++ = *ref_ptr++;
        }
    }
}

