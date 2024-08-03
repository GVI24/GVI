void inverse_transform(int16_t *block, int size) {
    int i, j;
    int16_t temp_block[64]; // Vulnerable fixed size assuming 8x8 blocks
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            // No bounds check, can cause overflow with size > 8
            temp_block[i * size + j] = block[j * size + i];
        }
    }
    // Inverse operation that would now work on potentially corrupted temp_block
    // ...
}
