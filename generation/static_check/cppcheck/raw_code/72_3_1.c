static void skipWhitespace(const char **stream, const char *streamEnd, UErrorCode *pErrorCode) {
    const char *source = *stream;
    while (source < streamEnd && isspace(*source)) {
        source++;
    }
    *stream = source;
    if (source >= streamEnd) {
        *pErrorCode = U_INDEX_OUTOFBOUNDS_ERROR;
    }
}