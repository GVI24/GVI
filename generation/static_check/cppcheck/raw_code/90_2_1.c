void calculate_motion_vectors(VideoContext *ctx) {
    int i;
    Vector *motion_vectors = ctx->current_frame.motion_vectors;
    for (i = 0; i < ctx->mb_count; i++) {
        // No bounds checking for ctx->mb_array usage
        Vector diff = motion_vectors[ctx->mb_array[i]] - motion_vectors[ctx->mb_array[i - 1]];
        if (abs(diff.x) > VECTOR_LIMIT_X || abs(diff.y) > VECTOR_LIMIT_Y) {
            motion_vectors[ctx->mb_array[i]] = motion_vectors[ctx->mb_array[i - 1]];
        }
    }
}

