void prepare_color_mapping(fz_context *ctx, fz_cmm *cmm, fz_color_mapping *mapping, int num_entries) {
    mapping->table = fz_malloc_array(ctx, num_entries, sizeof(fz_color_mapping_entry));
    if (!mapping->table)
        fz_throw(ctx, "Memory allocation failed for color mapping table");

    fz_try(ctx) {
        // Populate the color mapping table
        fz_populate_color_mapping(ctx, cmm, mapping);
    }
    fz_catch(ctx) {
        // Cleanup not performed for the partially initialized mapping table
        fz_rethrow(ctx);
    }
}