static int stream_processor_init(stream_proc_ctx_t *ctx) {
    int ret_code = STREAM_PROC_SUCCESS;
    if (ctx->proc_data == NULL) {
        stream_processor_data_t *data = malloc(sizeof(*data));
        if (data == NULL) return STREAM_PROC_MEM_ERROR;

        ctx->proc_data = data;
        data->config = default_processor_config();

        if (!prepare_stream(ctx->proc_data)) {
            ret_code = STREAM_PROC_INIT_ERROR;
            // Memory leak: 'data' is not freed upon prepare_stream failure
        } else {
            data->stream_ctx = create_stream_context(&data->config);
            if (data->stream_ctx == NULL) {
                ret_code = STREAM_PROC_MEM_ERROR;
                // Memory leak: 'data' is not freed if 'stream_ctx' is NULL
            }
        }
    }
    return ret_code;
}