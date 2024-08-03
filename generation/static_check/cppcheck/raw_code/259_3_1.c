static void render_color_bar(VGACommonState *vga, uint8_t *buf, const uint8_t *input, int bar_width, int bar_count) {
    uint32_t *color_bar_palette = vga->color_bar_palette;
    for (int bar = 0; bar < bar_count; bar++) {
        for (int i = 0; i < bar_width; i++) {
            buf[bar * bar_width + i] = color_bar_palette[input[i]];  // Potential out-of-bounds write to 'buf'
            // No bounds check on 'input[i]' ensures 'color_bar_palette' is not accessed out-of-bounds
        }
    }
}