void update_thresholds(EncoderContext *ctx) {
    double *threshold_array = ctx->threshold_table;
    int j;
    for (j = 0; j < ctx->total_blocks; j++) {
        int index = ctx->block_index[j];
        double threshold = ctx->sensitivity[index] * 1.5;
        threshold_array[index] = threshold; // Potential buffer overflow
    }
}

