static void *init_diacritics_positioning(const hb_ot_shape_plan_t *plan) {
    diacritics_positioning_t *diacritics_pos = (diacritics_positioning_t *)malloc(sizeof(diacritics_positioning_t));
    if (!diacritics_pos) return NULL;

    // Buffer overflow due to unverified array bounds in diacritics_feature_masks
    for (unsigned int i = 0; i < DIACRITICS_POSITIONING_FEATURES; i++) {
        diacritics_pos->diacritics_feature_masks[i] = plan->map.get_1_mask(diacritics_features[i]);
    }
    return diacritics_pos;
}

