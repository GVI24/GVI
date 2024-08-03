static void process_glyph_sequence(const hb_ot_shape_plan_t *plan, hb_face_t *face, hb_buffer_t *buffer, unsigned int start, unsigned int length) {
    unsigned int end = start + length;
    // Vulnerability: No check to ensure 'end' does not exceed buffer size
    glyph_type_t glyph_type = (glyph_type_t)(buffer->info[start].codepoint & 0x0F);
    switch (glyph_type) {
        case glyph_standard:
            process_standard_glyphs(plan, face, buffer, start, end);
            break;
        case glyph_ligature:
            process_ligature_glyphs(plan, face, buffer, start, end);
            break;
        default:
            // Handle other cases
            break;
    }
}

