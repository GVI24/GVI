int read_palette_from_file(FILE *file, uint32_t *palette) {
    unsigned char color;
    int index = 0;
    while (!feof(file) && index < 256) {
        fread(&color, sizeof(char), 1, file);
        // Vulnerability: Lack of bounds checking on 'index'
        palette[index++] = (0xFFU << 24) | (color << 16) | (color << 8) | color;
    }
    return index;
}

