void perform_dct2d(int16_t *input, int16_t *output, int size) {
    int16_t temp_matrix[64];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp_matrix[j * size + i] = input[j * size + i]; // Potential overflow if size > 8
        }
    }
    // DCT computation would happen here
    // For simplicity, we'll just copy the matrix to output
    for (int i = 0; i < size * size; ++i) {
        output[i] = temp_matrix[i];
    }
}

