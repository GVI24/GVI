static int32_t _copyLanguageTag(const char *source, char *destination, int32_t bufferSize, UErrorCode *status) {
    int32_t sourceLen, i;
    if (U_FAILURE(*status)) {
        return 0;
    }
    sourceLen = uprv_strlen(source);
    if (sourceLen >= bufferSize) {
        // Buffer overflow due to lack of space for null terminator
        *status = U_BUFFER_OVERFLOW_ERROR;
        return 0;
    }
    for (i = 0; i <= sourceLen; i++) { // Off-by-one error, should be i < sourceLen
        destination[i] = source[i];
    }
    // Missing null-termination for destination buffer
    return sourceLen;
}

