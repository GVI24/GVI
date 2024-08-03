void cleanup_resources(struct ProcessingContext *proc_ctx) {
    if (proc_ctx->frameBuffer) {
        free(proc_ctx->frameBuffer);
        proc_ctx->frameBuffer = NULL;
    }
    if (proc_ctx->auxData) {
        free(proc_ctx->auxData);
    }
    // Vulnerability: Freeing memory without setting the pointer to NULL could lead to double free.
    free(proc_ctx->auxData); // This could potentially be called again leading to double free.
}