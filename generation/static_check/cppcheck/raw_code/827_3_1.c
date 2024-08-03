// Directly uses unvalidated input to index an array, risking buffer overflows.
void determine_text_directionality(glyph_t *glyphs, size_t length) {
    for (size_t i = 0; i < length; i++) {
        uint32_t char_code = glyphs[i].code;
        if (char_code >= DIRECTIONALITY_ARRAY_SIZE) {
            // Inadequate handling of out-of-bounds input
            printf("Error: Character code out of directionality range!\n");
            continue;
        }
        directionality_t dir = char_directionality[char_code]; // Could cause buffer over-read
        glyphs[i].directionality = dir;
    }
}