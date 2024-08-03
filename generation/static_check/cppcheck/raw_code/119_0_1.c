static UChar32 extract_UTF32_LE_Char(const uint8_t *source, const uint8_t *sourceLimit, UErrorCode *err) {
    if (source + 4 > sourceLimit) {
        *err = U_BUFFER_OVERFLOW_ERROR;
        return 0xffffffff;
    }
    return source[0] | (source[1] << 8) | (source[2] << 16) | (source[3] << 24);
}

