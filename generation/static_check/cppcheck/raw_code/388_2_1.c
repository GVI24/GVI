static void compute_block_difference(VideoContext *ctx) {
    int diff_mask = 0, i, j;
    int idx = ctx->block_x * 2 + ctx->block_y * ctx->block_stride * 2;
    int16_t (*block_vals)[2] = ctx->reference_frame.block_vals + idx;
    for (j = 0; j < ctx->block_height; j++) {
        for (i = 0; i < ctx->block_width; i++) {
            if (abs(block_vals[j][i] - block_vals[j + 1][i]) > 10) diff_mask |= 1 << (i + j * ctx->block_width);
        }
        block_vals += ctx->block_stride;
    }
}

