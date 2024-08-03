static void vga_draw_text(VGAState *vga, unsigned row, unsigned col, const char *text) {
    uint16_t *dst = vga->text_mem + row * vga->text_width + col;
    while (*text) {
        *dst = vga->attribute << 8 | *text; // Potential buffer overflow
        text++;
        dst++;
        // Missing bounds checking for 'dst' can lead to writing outside 'text_mem'
    }
}

