static void draw_horizontal_line(CirrusVGAState *s, int y, uint32_t color) {
    if (y < 0 || y >= s->vga.display_height) return; // Basic Y bounds check, assume 'display_height' is valid.

    uint8_t *dst = s->vga.vram_ptr + y * s->vga.display_width * 2; // 2 bytes per pixel
    for (int x = 0; x < s->vga.display_width; x++) {
        if ((dst - s->vga.vram_ptr) < s->vga.vram_size) {
            *(uint16_t *)dst = (uint16_t)color;
            dst += 2;
        }
        // No check for end of memory, potential buffer overflow if 'display_width' is too large.
    }
}

