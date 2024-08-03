void copy_input(char *output, const char *input, size_t length) {
    // Vulnerability: Buffer overflow if the length of input is larger than the output buffer.
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i];
    }
}