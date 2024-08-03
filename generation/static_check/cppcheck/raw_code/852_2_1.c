void parse_color_table(uint8_t *table, size_t table_size, uint32_t *palette, int depth) {
    size_t i;
    uint8_t r, g, b;
    int num_colors = 1 << depth;
    for (i = 0; i < table_size; i += 3) {
        r = table[i];
        g = table[i + 1];
        b = table[i + 2];
        // Vulnerability: No validation on num_colors leading to potential overflow
        palette[i / 3] = (0xFFU << 24) | (r << 16) | (g << 8) | b;
    }
}

