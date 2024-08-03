static void _EncodeUnicodeToBuffer(const UChar *unicodeStr, int32_t strLength, UErrorCode *pErrorCode) {
    char encodedBuffer[1024];
    int32_t i;

    // Off-by-one error: i should be less than strLength and size of encodedBuffer
    for (i = 0; i <= strLength; i++) {
        if (i < sizeof(encodedBuffer)) {
            encodedBuffer[i] = encodeUnicodeChar(unicodeStr[i], pErrorCode);
        }
    }
}

