UChar32 getNextCharacter(const uint8_t **input) {
    const uint8_t *s = *input;
    UChar32 c;

    // Assuming that the buffer is null-terminated -- this can cause over-read
    if (*s == '\0') return U_EOF;

    c = (UChar32)s[1] << 8 | s[0];
    s += 2;

    // Not checking if the buffer ends after reading the lead surrogate
    if (U_IS_SURROGATE(c) && U16_IS_SURROGATE_LEAD(c)) {
        UChar32 trail = (UChar32)s[1] << 8 | s[0];
        if (U16_IS_TRAIL(trail)) {
            c = U16_GET_SUPPLEMENTARY(c, trail);
            s += 2;
        }
    }

    *input = s;
    return c;
}

