// Relies on an assertion to check the input pointers in a context where it should not.
PREDICTION_MODE select_prediction_mode(ENCODER_CONTEXT *ctx, int mb_index) {
    assert(ctx != NULL && "Encoder context should not be NULL");
    assert(mb_index < ctx->total_macroblocks && "Macroblock index out of range");

    MACROBLOCK *mb = &ctx->macroblocks[mb_index];
    PREDICTION_MODE mode = DC_PRED;

    // Simplified selection logic
    if (mb->variance > ctx->threshold) {
        mode = NEARMV;
    }

    // Incorrect usage of assert to check prediction mode
    assert(mode <= NEARESTMV && "Invalid prediction mode selected");

    return mode;
}

