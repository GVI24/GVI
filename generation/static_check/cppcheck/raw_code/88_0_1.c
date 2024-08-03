static int16_t *calculate_motion_vector(MotionContext *ctx, int *dx, int *dy) {
    int index = ctx->current_block_index;
    int stride = ctx->frame_stride;
    int16_t *motion_vectors = ctx->frame.motion_vectors;

    // Incorrect calculation of indices can lead to out-of-bounds access
    int16_t *left_vector = &motion_vectors[(index - 1) * 2];
    int16_t *top_vector = &motion_vectors[(index - stride) * 2];
    int16_t *top_right_vector = &motion_vectors[(index - stride + 1) * 2];

    *dx = (left_vector[0] + top_vector[0] + top_right_vector[0]) / 3;
    *dy = (left_vector[1] + top_vector[1] + top_right_vector[1]) / 3;
    
    return &motion_vectors[index * 2];
}

