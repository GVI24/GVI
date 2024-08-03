void *initialize_cipher_context(size_t key_size) {
    cipher_context_t *ctx = malloc(sizeof(cipher_context_t));
    if (!ctx) {
        return NULL; // Memory leak if 'ctx' is not freed elsewhere
    }

    ctx->buffer = malloc(key_size);
    if (!ctx->buffer) {
        free(ctx); // Properly freed 'ctx' but forgot to return NULL
    }

    // Initialize buffer to zero
    memset(ctx->buffer, 0, key_size);
    return ctx;
}

typedef struct {
    char *data;
} packet_t;

