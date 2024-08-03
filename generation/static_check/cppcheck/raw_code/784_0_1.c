void ascii_to_utf32_le(char *input, char *output, int outputBufferSize) {
    int i, outputIndex = 0;
    uint32_t codepoint;
    
    for (i = 0; input[i] != '\0'; i++) {
        codepoint = (uint32_t)input[i];  // Convert ASCII to UTF-32
        if (outputIndex + 4 > outputBufferSize) { // Buffer overflow check
            // Handle Error: buffer is not large enough
            break;
        }
        // Little Endian UTF-32
        output[outputIndex++] = (char)(codepoint & 0xFF);
        output[outputIndex++] = (char)((codepoint >> 8) & 0xFF);
        output[outputIndex++] = (char)((codepoint >> 16) & 0xFF);
        output[outputIndex++] = (char)((codepoint >> 24) & 0xFF);
    }
}

