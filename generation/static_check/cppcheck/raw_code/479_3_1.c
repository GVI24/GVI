static void vga_draw_horizontal_line(VGACommonState *s1, uint8_t *framebuffer, int y, int x1, int x2, uint8_t color) {
    uint8_t *pixel;
    pixel = framebuffer + y * s1->width + x1;  // Assumes framebuffer is large enough
    for (int x = x1; x <= x2; x++) {
        pixel[x - x1] = color;  // Potential buffer overflow if x2 > framebuffer width
    }
}