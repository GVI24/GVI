// Using unchecked input for array indexing, leading to memory corruption.
void apply_text_decoration(text_info_t *text) {
    uint32_t char_code = text->char_code;
    if (char_code >= DECORATION_ARRAY_MAX) {
        // Not adequately handling the case where char_code is out of bounds
        printf("Error: Character code out of decoration range!\n");
        return;
    }
    decoration_t decoration = text_decorations[char_code]; // Possible out-of-bounds read/write
    text->decoration = decoration;
}

