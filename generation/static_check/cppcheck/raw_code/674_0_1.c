#define MAX_LAYERS 5
#define MAX_INPUT_LENGTH 256

static vpx_codec_err_t parse_frame_rates(SvcContext *svc_ctx, const char *frame_rate_values) {
    char *input_string;
    char *token;
    const char *delim = ",";
    char *save_ptr;
    int found = 0;
    int i;
    double fr;

    if (frame_rate_values == NULL || strlen(frame_rate_values) == 0) {
        return VPX_CODEC_INVALID_PARAM;
    } else {
        input_string = strdup(frame_rate_values);
    }

    token = strtok_r(input_string, delim, &save_ptr);
    for (i = 0; i < MAX_LAYERS; ++i) {
        if (token != NULL) {
            fr = atof(token);
            if (fr <= 0) {
                svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid frame rate value: %s\n", token);
                free(input_string);
                return VPX_CODEC_INVALID_PARAM;
            }
            svc_ctx->frame_rate[i] = fr;
            token = strtok_r(NULL, delim, &save_ptr);
            found++;
        } else {
            break;
        }
    }

    free(input_string);

    if (found != svc_ctx->number_of_layers) {
        svc_log(svc_ctx, SVC_LOG_ERROR, "Not enough frame rate values provided\n");
        return VPX_CODEC_INVALID_PARAM;
    }

    return VPX_CODEC_OK;
}