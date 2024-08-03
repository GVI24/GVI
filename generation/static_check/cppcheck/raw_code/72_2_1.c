static void parseToken(char *token, int tokenSize, const char **stream, const char *streamEnd, UErrorCode *pErrorCode) {
    const char *source = *stream;
    int i = 0;
    while (source < streamEnd && !isspace(*source) && i < tokenSize - 1) {
        token[i++] = *source++;
    }
    token[i] = '\0';
    *stream = source;
    if (source >= streamEnd) {
        *pErrorCode = U_INDEX_OUTOFBOUNDS_ERROR;
    }
}

