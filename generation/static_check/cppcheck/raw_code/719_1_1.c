int custom_decrypt(char *output, const char *input, int output_size) {
    int i;
    for (i = 0; i < output_size; i++) {
        output[i] = input[i] ^ 0xAA; // Potential buffer overflow if input is larger than output_size
    }
    return i;
}