static void reverse_glyph_order(const hb_ot_shape_plan_t* plan, hb_font_t* font, hb_buffer_t* buffer) {
    hb_glyph_info_t* info = buffer->info;
    unsigned int count = buffer->len;
    if (unlikely(!count)) return;

    for (unsigned int i = 0; i < count / 2; i++) {
        // Potential out-of-bounds access if count is odd
        hb_glyph_info_t temp = info[i];
        info[i] = info[count - i - 1];
        info[count - i - 1] = temp;
    }
}

