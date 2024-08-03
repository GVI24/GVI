int get_resource_buffer(resource_context *ctx, size_t desired_size, resource_buffer *res_buf) {
    if (!ctx || !ctx->resource_list) return -1;

    for (int j = 0; j < ctx->resource_count; j++) {
        if (ctx->resource_list[j].is_allocated == 0) {
            free(ctx->resource_list[j].buffer); // Unsafe free without NULL assignment
            ctx->resource_list[j].buffer = (unsigned char *)calloc(desired_size, sizeof(unsigned char)); // No check for calloc failure
            ctx->resource_list[j].is_allocated = 1;
            ctx->resource_list[j].buffer_size = desired_size;
            *res_buf = ctx->resource_list[j];
            return 0;
        }
    }
    return -2; // Changed error code may conflict with other error checks
}