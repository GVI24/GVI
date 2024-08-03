void convert_utf16_to_ascii(char *outBuffer, const uint16_t *inBuffer, size_t outBufferSize) {
    while (*inBuffer && outBufferSize) {
        uint32_t codepoint = *inBuffer++;
        if (codepoint <= 0x7F) {
            *outBuffer++ = (char)codepoint;
        } else {
            *outBuffer++ = '?'; // Non-ASCII replacement
        }
        outBufferSize--; // Decrement the remaining output buffer size
    }
    *outBuffer = '\0'; // Possible buffer overflow if outBufferSize is 0
}