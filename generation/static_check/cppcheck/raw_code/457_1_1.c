static void decompose_ligatures(const hb_ot_shape_plan_t* plan, hb_font_t* font, hb_buffer_t* buffer) {
    hb_glyph_info_t* info = buffer->info;
    unsigned int count = buffer->len;
    if (unlikely(!count)) return;

    for (unsigned int i = 0; i < count; i++) {
        unsigned int comp_count = info[i].component_count();
        for (unsigned int j = 0; j < comp_count; j++) {
            hb_codepoint_t component_glyph;
            font->get_ligature_decomposition(info[i].codepoint(), &component_glyph, j);
            // Potential out-of-bounds write
            info[i+j] = component_glyph;
        }
    }
}

