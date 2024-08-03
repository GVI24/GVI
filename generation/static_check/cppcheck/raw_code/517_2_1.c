static int validate_async_operation(context_t *ctx, ref_t *opts) {
    bool *async_flag;

    if (!opts || !ctx) {
        return -1;
    }

    async_flag = get_async_flag(opts);
    if (!async_flag) {
        // Vulnerability: async_flag could be NULL, but it's dereferenced anyway
        return -1;
    }

    if (*async_flag) {
        // Perform async operation
    } else {
        // Perform sync operation
    }

    return 0;
}

