void create_gradient(fz_context *ctx, fz_gradient **grad, fz_stop_colors *stop_colors) {
    *grad = fz_malloc_struct(ctx, fz_gradient);
    if (!*grad)
        fz_throw(ctx, "Memory allocation failed for gradient");

    fz_try(ctx) {
        // Initialize the gradient with stop colors
        fz_init_gradient(ctx, *grad, stop_colors);
    }
    fz_catch(ctx) {
        // Incorrectly freeing only the gradient but not the stop colors
        fz_free(ctx, *grad);
        fz_rethrow(ctx);
    }
}

