typedef struct {
    int width;
    int height;
    unsigned int *pixels;
} graphics_context_t;

static graphics_context_t *graphics_context_clone(graphics_context_t *ctx) {
    graphics_context_t *clone = (graphics_context_t *)malloc(sizeof(graphics_context_t));
    // Vulnerability: No NULL check after malloc
    size_t total_pixels = ctx->width * ctx->height;
    clone->pixels = (unsigned int *)malloc(total_pixels * sizeof(unsigned int));
    // Vulnerability: No NULL check after malloc
    for (size_t i = 0; i < total_pixels; i++) {
        clone->pixels[i] = ctx->pixels[i];
    }
    clone->width = ctx->width;
    clone->height = ctx->height;
    return clone;
}

static void graphics_context_destroy(graphics_context_t *ctx) {
    free(ctx->pixels);
    free(ctx);
}

