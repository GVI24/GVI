void custom_encode(char *input, int inputLength, char *output, int outputCapacity) {
    int inputIndex = 0, outputIndex = 0;
    while (inputIndex < inputLength) {
        if (outputIndex + 3 >= outputCapacity) {
            // Output buffer overflow: Not enough space for encoding
            break;
        }
        // Custom encoding logic that expands one byte into three
        output[outputIndex++] = (input[inputIndex] & 0xF0) >> 4;
        output[outputIndex++] = (input[inputIndex] & 0x0F);
        output[outputIndex++] = (input[inputIndex] & 0xF0);
        inputIndex++;
    }
}