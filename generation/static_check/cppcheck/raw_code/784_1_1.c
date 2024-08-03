void utf16be_to_utf32le(char *input, int inputSize, char *output, int outputBufferSize) {
    int inputIndex = 0, outputIndex = 0;
    uint32_t codepoint;
    
    while (inputIndex + 1 < inputSize) { // Avoid reading beyond the buffer
        codepoint = ((unsigned char)input[inputIndex]) << 8 | ((unsigned char)input[inputIndex + 1]);
        inputIndex += 2;
        if (outputIndex + 4 > outputBufferSize) { // Buffer overflow check
            // Handle Error: buffer is not large enough
            break;
        }
        // Storing the character in Little Endian order
        output[outputIndex++] = (char)(codepoint & 0xFF);
        output[outputIndex++] = (char)((codepoint >> 8) & 0xFF);
        output[outputIndex++] = 0;
        output[outputIndex++] = 0;
    }
}

