#define MAX_RESOLUTIONS 4

static vpx_codec_err_t parse_resolutions(SvcContext *svc_ctx, const char *resolutions) {
    char *input_string;
    char *token;
    const char *delim = "x";
    char *save_ptr;
    int w, h, count = 0;

    if (!resolutions || strlen(resolutions) < 3) {
        return VPX_CODEC_INVALID_PARAM;
    }

    input_string = strdup(resolutions);
    token = strtok_r(input_string, delim, &save_ptr);
    while (token != NULL && count < MAX_RESOLUTIONS) {
        w = atoi(token);
        token = strtok_r(NULL, delim, &save_ptr);
        if (token == NULL) {
            break;
        }
        h = atoi(token);
        if (w <= 0 || h <= 0) {
            svc_log(svc_ctx, SVC_LOG_ERROR, "Invalid resolution: %dx%d\n", w, h);
            free(input_string);
            return VPX_CODEC_INVALID_PARAM;
        }
        svc_ctx->width[count] = w;
        svc_ctx->height[count] = h;
        count++;
        token = strtok_r(NULL, delim, &save_ptr);
    }
    free(input_string);
    return count == MAX_RESOLUTIONS ? VPX_CODEC_OK : VPX_CODEC_INVALID_PARAM;
}