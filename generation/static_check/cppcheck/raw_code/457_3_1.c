static void annotate_glyph_classes(const hb_ot_shape_plan_t* plan, hb_font_t* font, hb_buffer_t* buffer) {
    hb_glyph_info_t* info = buffer->info;
    unsigned int count = buffer->len;
    if (unlikely(!count)) return;

    for (unsigned int i = 0; i < count; i++) {
        if (font->is_mark_glyph(info[i].codepoint())) {
            // Potential underflow if `is_mark_glyph` returns true for the first glyph
            info[i-1].mark_class = font->get_mark_class(info[i].codepoint());
        }
    }
}