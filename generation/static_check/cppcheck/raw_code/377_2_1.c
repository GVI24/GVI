static void vga_draw_char(VGACommonState *s, uint8_t *vidmem, const char *font_data, int x, int y, char c) {
    int i, j;
    const char *bitmap = font_data + c * s->font_height; // Assuming fixed font size, could lead to out-of-bounds read

    for (i = 0; i < s->font_height; i++) { // No check if font_height could lead to 'vidmem' overflow
        for (j = 0; j < s->font_width; j++) {
            if (bitmap[i] & (1 << j)) {
                vidmem[(y + i) * s->line_width + (x + j)] = s->font_color; // No validation on 'vidmem' boundaries
            }
        }
    }
}

