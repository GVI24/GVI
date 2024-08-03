static void fill_rectangle_4bit(uint8_t *buffer, int buffer_width, int x, int y, int width, int height, uint8_t color) {
    int i, j;
    uint8_t color_pair = (color & 0x0F) | (color << 4);
    for (i = y; i < y + height; i++) {
        for (j = x; j < x + width; j += 2) {
            buffer[i * (buffer_width / 2) + j / 2] = color_pair; // Potential overflow
        }
    }
}

