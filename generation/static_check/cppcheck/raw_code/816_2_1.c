int calculate_intra_prediction(PREDICTION_CTX *pred_ctx, BLOCK *block, PREDICTION_MODE modes[10], int block_size) {
    PREDICTION_MODE temp_modes[10];
    for (int i = 0; i <= block_size; i++) { // off-by-one error, leading to out-of-bounds write
        temp_modes[i] = find_prediction_mode(pred_ctx, block, i);
    }
    memcpy(modes, temp_modes, sizeof(temp_modes));
    return 0;
}

