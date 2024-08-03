static void *copy_glyph_info(const hb_ot_shape_plan_t *plan) {
    glyph_info_t *glyph_info = (glyph_info_t *)malloc(sizeof(glyph_info_t));
    if (glyph_info == NULL) return NULL;

    // Potential buffer overflow if GLYPH_INFO_FEATURES exceeds size of info_masks array
    for (unsigned int i = 0; i < GLYPH_INFO_FEATURES; i++) {
        glyph_info->info_masks[i] = plan->map.get_1_mask(glyph_features[i]);
    }
    return glyph_info;
}

