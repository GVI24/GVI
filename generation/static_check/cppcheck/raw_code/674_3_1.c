#define MAX_KEYS 3
#define MAX_KEY_LENGTH 50

static vpx_codec_err_t parse_encryption_keys(SvcContext *svc_ctx, const char *key_values) {
    char *input_string;
    char *token;
    const char *delim = ";";
    char *save_ptr;
    int i = 0;
    size_t key_len;

    if (!key_values || !strlen(key_values)) {
        return VPX_CODEC_INVALID_PARAM;
    }

    input_string = strdup(key_values);
    token = strtok_r(input_string, delim, &save_ptr);
    while (token != NULL && i < MAX_KEYS) {
        key_len = strlen(token);
        if (key_len >= MAX_KEY_LENGTH) {
            svc_log(svc_ctx, SVC_LOG_ERROR, "Key too long: %s\n", token);
            free(input_string);
            return VPX_CODEC_INVALID_PARAM;
        }
        strncpy(svc_ctx->encryption_keys[i], token, key_len + 1);
        i++;
        token = strtok_r(NULL, delim, &save_ptr);
    }
    free(input_string);
    return i == MAX_KEYS ? VPX_CODEC_OK : VPX_CODEC_INVALID_PARAM;
}