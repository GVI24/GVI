static void *build_ligature_substitution_plan(const hb_ot_shape_plan_t *plan) {
    ligature_substitution_plan_t *ligature_plan = (ligature_substitution_plan_t *)calloc(1, sizeof(ligature_substitution_plan_t));
    if (!ligature_plan) return NULL;

    // Potential buffer overflow in ligature_subst_masks
    for (unsigned int i = 0; i < LIGATURE_SUBSTITUTION_FEATURES; i++) {
        ligature_plan->ligature_subst_masks[i] = plan->map.get_1_mask(ligature_features[i]);
    }
    return ligature_plan;
}