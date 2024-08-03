static int readIntegerFromStream(const char **stream, const char *streamEnd, UErrorCode *pErrorCode) {
    const char *source = *stream;
    int value = 0;
    if (source < streamEnd) {
        while (source < streamEnd && isdigit(*source)) {
            value = value * 10 + (*source - '0');
            source++;
        }
        *stream = source;
        return value;
    }
    *pErrorCode = U_INDEX_OUTOFBOUNDS_ERROR;
    return -1;
}

