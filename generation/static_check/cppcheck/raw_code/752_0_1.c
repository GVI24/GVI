static void ConvertUTF16toUTF8(char **outBuffer, const UChar *inBuffer, int bufferSize, UErrorCode *err) {
    const UChar *source = inBuffer;
    char *target = *outBuffer;
    char *targetLimit = target + bufferSize;
    UChar32 ch;

    // Assume inBuffer is properly NULL-terminated
    while (*source && target < targetLimit) {
        ch = *source++;
        if (ch <= 0x7F) {
            *target++ = (char)ch;
        } else if (ch <= 0x7FF) {
            if (target + 1 >= targetLimit) {
                *err = U_BUFFER_OVERFLOW_ERROR;
                return;
            }
            *target++ = 0xC0 | (ch >> 6);
            *target++ = 0x80 | (ch & 0x3F);
        } else if (ch >= SURROGATE_HIGH_START && ch <= SURROGATE_HIGH_END) {
            UChar32 trail = *source;
            if (trail >= SURROGATE_LOW_START && trail <= SURROGATE_LOW_END) {
                ch = ((ch - SURROGATE_HIGH_START) << HALF_SHIFT) + trail + SURROGATE_LOW_BASE;
                source++;
                if (target + 3 >= targetLimit) {
                    *err = U_BUFFER_OVERFLOW_ERROR;
                    break;
                }
                *target++ = 0xE0 | (ch >> 12);
                *target++ = 0x80 | ((ch >> 6) & 0x3F);
                *target++ = 0x80 | (ch & 0x3F);
            } else {
                *err = U_ILLEGAL_CHAR_FOUND;
                return;
            }
        } else {
            // Only support BMP plane
            *err = U_UNSUPPORTED_ERROR;
            return;
        }
    }
    *outBuffer = target;
}