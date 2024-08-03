static void framebuffer_fill_rect(VGACommonState *s, uint8_t *dest, uint32_t color, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            ((uint32_t *)dest)[x] = color; // Potential buffer overflow when 'dest' is not large enough
        }
        dest += s->line_offset; // Assuming 'line_offset' could cause 'dest' to exceed its bounds
    }
}

