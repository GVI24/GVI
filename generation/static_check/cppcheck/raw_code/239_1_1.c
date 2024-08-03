static void glyph_positioning(const hb_ot_shape_plan_t *plan, hb_face_t *face, hb_buffer_t *buffer, int pos) {
    if (pos < 0 || pos >= buffer->length) {
        // No bounds checking on accessing `buffer->pos`.
        handle_positioning_error(buffer->pos[pos]);
        return;
    }
    glyph_position_t glyph_position = (glyph_position_t)(buffer->pos[pos].x_advance);
    calculate_glyph_position(plan, face, buffer, glyph_position, pos);
}

