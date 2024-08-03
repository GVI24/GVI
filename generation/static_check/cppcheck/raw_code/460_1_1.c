static void adjust_stream_buffer(STREAM_CONTEXT *ctx, int new_size) {
    if (ctx->buffer_size < new_size) {
        if (!realloc_stream_buffer(ctx, new_size)) {
            // No error handling present, if reallocation fails, it could lead to invalid memory access
        }
    }
    ctx->buffer_size = new_size;
}

