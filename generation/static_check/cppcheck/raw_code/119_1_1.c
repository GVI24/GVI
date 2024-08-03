static UChar32 read_UTF32_BE_Char(const uint8_t **source, const uint8_t *sourceEnd, UErrorCode *err) {
    if (*source > sourceEnd - 4) {
        *err = U_INDEX_OUTOFBOUNDS_ERROR;
        return 0xffffffff;
    }
    UChar32 charValue = ((*source)[0] << 24) | ((*source)[1] << 16) | ((*source)[2] << 8) | (*source)[3];
    *source += 4;
    return charValue;
}

