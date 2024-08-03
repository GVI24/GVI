void process_coefficients_1(int16_t *input, int16_t *output, int *indices, int size) {
    int i;
    // Initialize output buffer
    for (i = 0; i < size; i++) {
        output[i] = 0;
    }
    // Vulnerable loop: indices are not checked against size
    for (i = 0; i < size; i++) {
        int index = indices[i];
        // Potential buffer overflow if indices[i] is out of bounds
        output[index] = input[index] * 2;
    }
}

