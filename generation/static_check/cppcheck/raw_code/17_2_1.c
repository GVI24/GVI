static void apply_color_filter(uint8_t *frame, uint32_t color_filter, int width, int height) {
    uint8_t *pixel = frame;
    int i;
    for (i = 0; i < width * height; i++) {
        uint32_t color = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];
        color &= color_filter;
        *pixel++ = (color >> 16) & 0xFF; // Red
        *pixel++ = (color >> 8) & 0xFF;  // Green
        *pixel++ = color & 0xFF;         // Blue
    }
}

