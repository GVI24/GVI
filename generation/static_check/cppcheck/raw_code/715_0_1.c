static vpx_codec_err_t parse_layer_bitrates(SvcContext *svc_ctx, const char *bitrate_options) {
    char *input_string;
    char *token;
    const char *delim = ",";
    char *save_ptr;
    int i, bitrate;
    vpx_codec_err_t res = VPX_CODEC_OK;
    SvcInternal * const si = get_svc_internal(svc_ctx);

    if (bitrate_options == NULL || bitrate_options[0] == '\0') {
        return VPX_CODEC_INVALID_PARAM;
    } else {
        input_string = strdup(bitrate_options);
        if (!input_string) {
            return VPX_CODEC_MEM_ERROR;
        }
    }

    token = strtok_r(input_string, delim, &save_ptr);
    for (i = 0; i < si->number_of_layers && token != NULL; i++) {
        bitrate = atoi(token);
        if (bitrate <= 0) {
            svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid bitrate value: %d\n", bitrate);
            res = VPX_CODEC_INVALID_PARAM;
            break;
        }
        si->layer_target_bitrate[i] = bitrate;
        token = strtok_r(NULL, delim, &save_ptr);
    }

    if (i != si->number_of_layers) {
        svc_log(svc_ctx, SVC_LOG_ERROR, "Not enough bitrate values provided.\n");
        res = VPX_CODEC_INVALID_PARAM;
    }

    free(input_string);
    return res;
}

