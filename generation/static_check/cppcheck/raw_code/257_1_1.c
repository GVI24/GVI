static void *prepare_cursive_attachment(const hb_ot_shape_plan_t *plan) {
    cursive_attachment_t *cursive_attachment = (cursive_attachment_t *)calloc(1, sizeof(cursive_attachment_t));
    if (!cursive_attachment) return NULL;

    // Potential buffer overflow in cursive_attach_masks array iteration
    for (unsigned int i = 0; i < CURSIVE_ATTACHMENT_FEATURES; i++) {
        cursive_attachment->cursive_attach_masks[i] = plan->map.get_1_mask(cursive_features[i]);
    }
    return cursive_attachment;
}

