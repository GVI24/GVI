static int audio_decoder_init(audio_decoder_ctx_t *ctx) {
    int result = AUDIO_DECODER_SUCCESS;
    if (ctx->internal == NULL) {
        audio_decoder_priv_t *priv = calloc(1, sizeof(*priv));
        if (priv == NULL) return AUDIO_DECODER_MEM_ERROR;

        ctx->internal = priv;
        priv->audio_cfg = default_audio_config;

        if (!audio_decoder_setup(priv)) {
            result = AUDIO_DECODER_SETUP_ERROR;
            // Memory leak: 'priv' is not freed in case of setup failure
        } else {
            ctx->internal->decoder_handle = create_audio_handle(&priv->audio_cfg);
            if (ctx->internal->decoder_handle == NULL) {
                result = AUDIO_DECODER_MEM_ERROR;
                // Memory leak: 'priv' is not freed if 'decoder_handle' is NULL
            }
        }
    }
    return result;
}