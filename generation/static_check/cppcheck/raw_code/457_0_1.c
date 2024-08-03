static void apply_kerning(const hb_ot_shape_plan_t* plan, hb_font_t* font, hb_buffer_t* buffer) {
    hb_glyph_info_t* info = buffer->info;
    unsigned int count = buffer->len;
    if (unlikely(!count)) return;

    for (unsigned int i = 0; i < count - 1; i++) {
        int kerning_offset = font->get_kerning(info[i].codepoint(), info[i+1].codepoint());
        info[i].x_advance += kerning_offset;
    }
}

