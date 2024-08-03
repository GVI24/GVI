static void ConvertUTF8toASCII(const char *utf8Input, char *asciiOutput, size_t asciiBufferSize, UErrorCode *err) {
    const unsigned char *source = (const unsigned char *)utf8Input;
    char *target = asciiOutput;
    char *targetEnd = asciiOutput + asciiBufferSize;

    while (*source && target < targetEnd) {
        if ((*source & 0x80) == 0) { // ASCII character
            *target++ = *source++;
        } else {
            // Skip UTF-8 continuation bytes for simplicity (lossy conversion)
            while (*source && (*source & 0xC0) == 0x80) {
                source++;
            }
            // Convert non-ASCII characters to '?'
            *target++ = '?';
            source++;
        }
    }

    if (target >= targetEnd && *source) {
        // Not enough space for all characters
        *err = U_BUFFER_OVERFLOW_ERROR;
    } else {
        *target = '\0'; // Ensure null termination
    }
}