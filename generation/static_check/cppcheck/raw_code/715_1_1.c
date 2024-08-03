static vpx_codec_err_t configure_temporal_layer_rates(SvcContext *svc_ctx, const char *rates_string) {
    char *input;
    char *token;
    const char *delim = ";";
    char *save_ptr;
    int layer_rate;
    vpx_codec_err_t res = VPX_CODEC_OK;
    if (!rates_string || !*rates_string) {
        return VPX_CODEC_INVALID_PARAM;
    }
    input = strdup(rates_string);
    if (!input) {
        return VPX_CODEC_MEM_ERROR;
    }

    token = strtok_r(input, delim, &save_ptr);
    for (int i = 0; i < REF_FRAMES; i++) {
        if (token) {
            layer_rate = atoi(token);
            if (layer_rate < 1) {
                svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid layer rate: %d\n", layer_rate);
                res = VPX_CODEC_INVALID_PARAM;
                break;
            }
            svc_ctx->layer_rates[i] = layer_rate;
            token = strtok_r(NULL, delim, &save_ptr);
        } else {
            svc_ctx->layer_rates[i] = DEFAULT_RATE;
        }
    }

    free(input);
    return res;
}

