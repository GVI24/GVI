void custom_process_block(const int16_t *input, uint8_t *dest, int stride) {
    int i, j;
    int16_t temp;
    for (i = 0; i < 8; i++) {
        temp = input[0] * (i + 1); // Simplified processing for example
        for (j = 0; j < 8; j++) {
            dest[j] = dest[j] + temp; // No bounds checking
        }
        dest += stride; // Potential overflow if stride is large
    }
}
