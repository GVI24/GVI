void draw_rectangle(uint32_t *framebuffer, int fb_width, int fb_height, int x, int y, int rect_width, int rect_height, uint32_t color) {
    for (int i = 0; i < rect_height; ++i) {
        for (int j = 0; j < rect_width; ++j) {
            int idx = (y + i) * fb_width + (x + j); // Potential out-of-bounds write
            framebuffer[idx] = color; // No bounds check, could overflow if x, y, rect_width, or rect_height are too large
        }
    }
}