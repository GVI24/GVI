static void vga_set_region_color(VGACommonState *s1, uint8_t *framebuffer, int x, int y, int width, int height, uint8_t color) {
    uint8_t *pixel;
    for (int i = 0; i < height; i++) {
        pixel = framebuffer + (y + i) * s1->width + x;  // Assumes framebuffer is large enough
        for (int j = 0; j < width; j++) {
            pixel[j] = color;  // Potential buffer overflow if x+width exceeds framebuffer width
        }
    }
}

