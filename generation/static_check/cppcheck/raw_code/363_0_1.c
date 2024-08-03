void jpc_enc_context_destroy(jpc_enc_context_t *ctx) {
    if (ctx->options) {
        jas_free(ctx->options);
    }
    if (ctx->stream) {
        jpc_stream_destroy(ctx->stream);
    }
    jas_free(ctx);
}

