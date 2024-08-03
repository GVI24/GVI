void convertASCIItoUTF16(char *input, uint16_t *output, int *outputSize) {
    int inputLength = strlen(input);
    int outputIndex = 0;

    for (int i = 0; i < inputLength; i++) {
        if (input[i] < 128) {
            // Potential buffer overflow if outputSize is less than inputLength
            output[outputIndex++] = (uint16_t)input[i];
        } else {
            // Handle non-ASCII character
            output[outputIndex++] = 0xFFFD; // Unicode replacement character
        }
    }

    *outputSize = outputIndex;
}