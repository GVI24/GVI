void select_prediction_mode(PredictionContext *pred_ctx) {
    int block_position = pred_ctx->block_position;

    // Assuming MAX_BLOCKS is the valid size of prediction_modes.
    // No boundary check for block_position can lead to out-of-bounds access
    pred_ctx->current_prediction_mode = pred_ctx->prediction_modes[block_position];
    pred_ctx->next_prediction_mode = pred_ctx->prediction_modes[block_position + 1];

    // Decision logic for prediction mode based on the current and next modes
    // ...
}