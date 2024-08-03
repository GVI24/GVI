static vpx_codec_err_t set_spatial_layer_resolutions(SvcContext *svc_ctx, const char *resolutions) {
    char *input;
    char *token;
    char *save_ptr;
    const char delim[] = "|";
    int width, height;
    vpx_codec_err_t res = VPX_CODEC_OK;

    if (!resolutions || !*resolutions) {
        return VPX_CODEC_INVALID_PARAM;
    }
    input = strdup(resolutions);
    if (!input) {
        return VPX_CODEC_MEM_ERROR;
    }

    token = strtok_r(input, delim, &save_ptr);
    for (int i = 0; i < svc_ctx->spatial_layers && token; i++) {
        sscanf(token, "%dx%d", &width, &height);
        if (width <= 0 || height <= 0) {
            svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid resolution: %s\n", token);
            res = VPX_CODEC_INVALID_PARAM;
            break;
        }
        svc_ctx->spatial_layer_resolutions[i].width = width;
        svc_ctx->spatial_layer_resolutions[i].height = height;
        token = strtok_r(NULL, delim, &save_ptr);
    }

    if (res == VPX_CODEC_OK && (token || (!token && i < svc_ctx->spatial_layers))) {
        svc_log(svc_ctx, SVC_LOG_ERROR, "Incorrect number of resolutions provided.\n");
        res = VPX_CODEC_INVALID_PARAM;
    }

    free(input);
    return res;
}

