static void example_pred_mv1(VideoContext *ctx, int block_type, int block_num) {
    int *motion_vectors = ctx->motion_vectors;
    int block_width = ctx->block_width;
    int block_height = ctx->block_height;
    int width = ctx->width;
    int current_pos = block_num * block_width;
    int A[2] = {0}, B[2] = {0}, C[2] = {0};

    if (block_num % width != 0) {
        A[0] = motion_vectors[current_pos - 2];
        A[1] = motion_vectors[current_pos - 1];
    }

    if (block_num >= width) {
        B[0] = motion_vectors[current_pos - width * 2];
        B[1] = motion_vectors[current_pos - width * 2 + 1];
    }

    if ((block_num + 1) % width != 0) {
        C[0] = motion_vectors[current_pos + 2];
        C[1] = motion_vectors[current_pos + 3];
    } else {
        C[0] = A[0];
        C[1] = A[1];
    }

    motion_vectors[current_pos] = (A[0] + B[0] + C[0]) / 3;
    motion_vectors[current_pos + 1] = (A[1] + B[1] + C[1]) / 3;
}

