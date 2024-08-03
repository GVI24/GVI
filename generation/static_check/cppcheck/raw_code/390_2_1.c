static void draw_line(struct render_state *rs, int x0, int y0, int x1, int y1, uint32_t color) {
    uint8_t *display_buffer = rs->buffer;
    int buf_width = rs->buffer_width;
    uint8_t color_val[4] = {color, color >> 8, color >> 16, color >> 24};

    // Off-by-one error can cause a write beyond the buffer
    for (int x = x0; x <= x1; x++) {
        for (int k = 0; k < sizeof(color_val); k++) { // Should be less than, not less than or equal
            display_buffer[(y0 * buf_width + x) * sizeof(color_val) + k] = color_val[k];
        }
    }
}

