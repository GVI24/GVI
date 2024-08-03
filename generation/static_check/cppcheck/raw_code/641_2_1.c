void substitute_glyphs(const hb_ot_shape_plan_t *plan, hb_buffer_t *buffer, unsigned int start) {
    hb_glyph_info_t *info = buffer->info;
    unsigned int count = buffer->length;
    for (unsigned int i = start; i < count; i++) {
        // Vulnerable: no bounds checking for i + 1 or i + 2
        if (info[i].codepoint == OT_Ligature_Target && info[i + 1].codepoint == OT_Ligature_Mark) {
            form_ligature(&info[i], &info[i + 1]);
            i += 1; // Skip next since it's part of the ligature now
        }
        // Some additional logic...
    }
}

