static void draw_rectangle(ScreenBuffer *screen, int rect_x, int rect_y, int width, int height) {
    int screen_width = screen->width;
    uint32_t *pixel_buffer = screen->pixels + (rect_y * screen_width) + rect_x;
    uint32_t color = 0xFF0000FF; // Red color

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel_buffer[x] = color; // Potential out-of-bounds write
        }
        pixel_buffer += screen_width;
    }
}