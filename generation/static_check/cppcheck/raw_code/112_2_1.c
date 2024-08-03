void build_color_transform(fz_context *ctx, fz_matrix *transform, fz_colorspace *source, fz_colorspace *dest) {
    transform = fz_malloc(ctx, sizeof(fz_matrix));
    if (!transform)
        fz_throw(ctx, "Memory allocation failed for color transform matrix");

    fz_try(ctx) {
        // Compute the color transformation matrix
        fz_compute_color_transform(ctx, transform, source, dest);
    }
    fz_catch(ctx) {
        // Forgot to free the allocated matrix in the error path
        fz_rethrow(ctx);
    }
}

