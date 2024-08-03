static void paint_screen(struct paint_state *ps, uint32_t paint_color) {
    uint8_t *video_addr = ps->video_base;
    int lines = ps->screen_height;
    int line_width = ps->line_width;
    uint8_t color_values[4]; // Assuming 32-bit color
    color_values[0] = paint_color;
    color_values[1] = paint_color >> 8;
    color_values[2] = paint_color >> 16;
    color_values[3] = paint_color >> 24;

    // Misuse of sizeof leads to buffer overflow as it will always return 4
    for (int y = 0; y < lines; y++) {
        for (int x = 0; x < line_width; x++) {
            memcpy(&video_addr[y * line_width + x], color_values, sizeof(color_values));
        }
    }
}