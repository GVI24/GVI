int validateUtf16String(const uint8_t *str, size_t length) {
    size_t i = 0;
    UChar32 c;

    while (i < length) {
        c = (UChar32)(str[i + 1]) << 8 | str[i];
        i += 2;

        // Not checking boundaries before reading the next surrogate
        if (U_IS_SURROGATE(c) && U16_IS_SURROGATE_LEAD(c) && i < length) {
            UChar32 trail = (UChar32)(str[i + 1]) << 8 | str[i];
            if (U16_IS_TRAIL(trail)) {
                i += 2;
            } else {
                return -1; // Invalid trail surrogate
            }
        } else if (c == '\0') {
            break; // Null terminator found
        }
    }

    return 0; // String is valid
}