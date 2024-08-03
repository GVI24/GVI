void load_bitmap_with_profile(fz_context *ctx, const char *filepath, fz_bitmap **bitmap, fz_colorspace *profile) {
    *bitmap = fz_malloc(ctx, sizeof(fz_bitmap));
    if (!*bitmap)
        fz_throw(ctx, "Memory allocation failed for bitmap");

    fz_try(ctx) {
        // Load bitmap from file
        *bitmap = fz_load_bitmap(ctx, filepath);
        // Apply color profile to the bitmap
        fz_apply_color_profile(ctx, *bitmap, profile);
    }
    fz_catch(ctx) {
        // Forgot to free the bitmap before re-throwing the exception
        fz_rethrow(ctx);
    }
}

