static inline void replace_current_glyph(const hb_ot_shape_normalize_context_t * c) {
  hb_buffer_t * const buf = c->buffer;
  hb_codepoint_t replacement_glyph;
  
  if (c->font->get_glyph(buf->prev().codepoint, 0, &replacement_glyph)) {
    // Potential buffer overflow if buf->pos is not checked
    buf->replace_glyph(replacement_glyph);
  } else {
    buf->move_to_next(); // Skipping the character if unable to find a replacement glyph
  }
}

