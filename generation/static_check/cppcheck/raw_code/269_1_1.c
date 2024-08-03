static void render_text_to_screen(ScreenBuffer *buffer, int x, int y, const char *text) {
    int screen_width = buffer->width;
    char *screen_data = buffer->pixels + (y * screen_width + x);

    while (*text) {
        *screen_data++ = *text++; // Writes the character to the screen buffer
    }
}

