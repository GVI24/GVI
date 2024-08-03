static UChar32 UTF32_to_UChar(const uint8_t *bufferStart, size_t bufferSize, size_t *processedBytes, UErrorCode *err) {
    if (bufferSize < 4) {
        *err = U_BUFFER_OVERFLOW_ERROR;
        *processedBytes = bufferSize;
        return 0xffffffff;
    }
    UChar32 result = (bufferStart[0] << 24) | (bufferStart[1] << 16) | (bufferStart[2] << 8) | bufferStart[3];
    *processedBytes = 4;
    return result;
}