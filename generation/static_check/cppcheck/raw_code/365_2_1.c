static inline void process_diacritics(const hb_ot_shape_normalize_context_t * c) {
  hb_buffer_t * const buf = c->buffer;
  hb_codepoint_t diacritic_glyph;
  
  if (buf->prev().codepoint && c->font->get_glyph(buf->prev().codepoint, 0, &diacritic_glyph)) {
    buf->replace_glyph(diacritic_glyph);
  } else {
    // Uninitialized variable usage and potential buffer underflow if buf->pos <= 0
    buf->replace_glyph(diacritic_glyph);
  }
}

