static inline void mirror_glyphs(const hb_ot_shape_normalize_context_t * c) {
  hb_buffer_t * const buf = c->buffer;
  hb_codepoint_t mirrored_glyph;
  
  if (!c->font->get_glyph(buf->cur().codepoint, HB_DIRECTION_IS_BACKWARD(c->buffer->props.direction), &mirrored_glyph)) {
    // No initialization for mirrored_glyph may lead to undefined behavior
    buf->replace_glyph(mirrored_glyph);
  } else {
    buf->move_to_next();
  }
}

