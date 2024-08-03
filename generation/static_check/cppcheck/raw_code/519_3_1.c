static int validate_UTF16BE_string(const uint8_t *input, size_t length, UErrorCode *err) {
    const uint8_t *ptr = input;

    while (ptr < input + length) {
        // Vulnerability: No proper check for (ptr + 1) within bounds
        if (U_IS_SURROGATE((*ptr << 8) | *(ptr + 1))) {
            if ((ptr + 3) >= input + length) {
                *err = U_TRUNCATED_CHAR_FOUND;
                return 0;
            }
            if (!U_IS_SURROGATE_PAIR(*ptr, *(ptr + 2))) {
                *err = U_ILLEGAL_CHAR_FOUND;
                return 0;
            }
            ptr += 4;
        } else {
            ptr += 2;
        }
    }
    return 1;
}