static vpx_codec_err_t parse_frame_rates(SvcContext *svc_ctx, const char *frame_rates) {
    char *input;
    char *token;
    const char *delim = "-";
    char *save_ptr;
    float rate;
    vpx_codec_err_t res = VPX_CODEC_OK;

    if (frame_rates == NULL || *frame_rates == '\0') {
        return VPX_CODEC_INVALID_PARAM;
    }
    input = strdup(frame_rates);
    if (!input) {
        return VPX_CODEC_MEM_ERROR;
    }

    token = strtok_r(input, delim, &save_ptr);
    for (int i = 0; i < svc_ctx->spatial_layers; i++) {
        if (token) {
            rate = atof(token);
            if (rate <= 0.0) {
                svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid frame rate: %f\n", rate);
                res = VPX_CODEC_INVALID_PARAM;
                break;
            }
            svc_ctx->framerate[i] = rate;
            token = strtok_r(NULL, delim, &save_ptr);
        } else {
            svc_log(svc_ctx, SVC_LOG_ERROR, "Missing frame rate for layer: %d\n", i);
            res = VPX_CODEC_INVALID_PARAM;
            break;
        }
    }

    if (res == VPX_CODEC_OK && (token || (!token && i < svc_ctx->spatial_layers))) {
        svc_log(svc_ctx, SVC_LOG_ERROR, "Incorrect number of frame rates provided.\n");
        res = VPX_CODEC_INVALID_PARAM;
    }

    free(input);
    return res;
}