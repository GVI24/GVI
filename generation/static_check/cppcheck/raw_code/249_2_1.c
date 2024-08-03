static int decode_macroblock(YopDecContext *ctx, int macroblock_size) {
    if (ctx->macroblock_end - ctx->macroblock_ptr < macroblock_size) {
        av_log(ctx->avctx, AV_LOG_ERROR, "Macroblock data is too small.\n");
        return AVERROR_INVALIDDATA;
    }
    int *lut = macroblock_lut[macroblock_size]; // Assume this LUT exists
    for(int i = 0; i < macroblock_size; i++) {
        ctx->current_frame[i] = ctx->macroblock_ptr[lut[i]]; // Potential out-of-bounds read
    }
    ctx->macroblock_ptr += macroblock_size;
    return 0;
}

