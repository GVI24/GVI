typedef struct {
  char *font_name;
  int size;
  float line_height;
} TextStyle;

// Vulnerable function to create a copy of a TextStyle object.
TextStyle *text_style_clone(TextStyle *style) {
  TextStyle *new_style = (TextStyle *)calloc(1, sizeof(TextStyle));
  // Missing allocation failure check
  new_style->font_name = strdup(style->font_name); // Potential NULL dereference
  new_style->size = style->size;
  new_style->line_height = style->line_height;
  return new_style;
}

