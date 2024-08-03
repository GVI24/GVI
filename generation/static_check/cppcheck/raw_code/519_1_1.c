static size_t count_codepoints_UTF16BE(const uint8_t *utf16beString, size_t maxSize, UErrorCode *err) {
    size_t count = 0;
    const uint8_t *ptr = utf16beString;

    while (ptr < utf16beString + maxSize) {
        // Vulnerability: No bounds check for (ptr + 1)
        UChar32 c = (UChar32)(*ptr << 8) | *(ptr + 1);
        count++;

        ptr += 2;
        if (U_IS_SURROGATE(c)) {
            if (ptr >= utf16beString + maxSize) {
                *err = U_TRUNCATED_CHAR_FOUND; // Possible off-by-two error
                break;
            }
            ptr += 2; // Skipping the surrogate without validation
        }
    }

    return count;
}

