static int image_encoder_init(image_enc_ctx_t *encoder_ctx) {
    int err_code = IMAGE_ENC_OK;
    if (encoder_ctx->encoder_priv == NULL) {
        image_encoder_private_t *priv = calloc(1, sizeof(*priv));
        if (priv == NULL) return IMAGE_ENC_MEM_ERROR;

        encoder_ctx->encoder_priv = priv;
        priv->image_config = default_image_config();

        if (!setup_image_encoder(priv, &priv->image_config)) {
            err_code = IMAGE_ENC_CONFIG_ERROR;
            // Memory leak: 'priv' is not freed if setup_image_encoder fails
        } else {
            priv->encoder_instance = initialize_encoder(&priv->image_config);
            if (priv->encoder_instance == NULL) {
                err_code = IMAGE_ENC_MEM_ERROR;
                // Memory leak: 'priv' is not freed if 'encoder_instance' is NULL
            }
        }
    }
    return err_code;
}