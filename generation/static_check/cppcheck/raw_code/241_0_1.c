// Example 1
static int get_free_decoder_slot(DecoderContext *ctx) {
    int i;
    for (i = 0; i <= ctx->max_decoders; i++) {
        if (!ctx->decoders[i].is_active) {
            return i;
        }
    }
    return -1;
}