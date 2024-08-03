#define MAX_BITRATES 3

static vpx_codec_err_t parse_bitrates(SvcContext *svc_ctx, const char *bitrate_values) {
    char *input_string;
    char *token;
    const char *delim = ":";
    char *save_ptr;
    int found = 0;
    int i;
    long br;

    if (!bitrate_values || !strlen(bitrate_values)) {
        return VPX_CODEC_INVALID_PARAM;
    }

    input_string = strdup(bitrate_values);
    token = strtok_r(input_string, delim, &save_ptr);
    for (i = 0; i < MAX_BITRATES; ++i) {
        if (token) {
            br = strtol(token, NULL, 10);
            if (br <= 0) {
                svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid bitrate value: %s\n", token);
                free(input_string);
                return VPX_CODEC_INVALID_PARAM;
            }
            svc_ctx->bitrate[i] = br;
            token = strtok_r(NULL, delim, &save_ptr);
            found++;
        }
    }
    free(input_string);
    return found == svc_ctx->spatial_layers ? VPX_CODEC_OK : VPX_CODEC_INVALID_PARAM;
}