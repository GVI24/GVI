void render_text_to_buffer(const char *text, uint8_t *screen_buffer, int buffer_size, int line_width) {
    int cursor_position = 0;
    while (*text) {
        // No check for cursor_position against buffer_size can result in buffer overflow
        if (*text == '\n') {
            cursor_position += line_width - (cursor_position % line_width);
        } else {
            screen_buffer[cursor_position++] = *text;
        }
        text++;
    }
}

// Helper functions used in the examples (assuming implementation exists)
int decode_sample(int16_t sample); // Decodes a single audio sample
uint8_t apply_filter(const int16_t *filter, uint8_t *pixel); // Applies a filter to a pixel