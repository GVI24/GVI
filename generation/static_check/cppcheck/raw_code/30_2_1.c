void quantize_block(int16_t *coefficients, int16_t *quantized, int block_size, int16_t *quantization_values) {
    int16_t temp[64];
    for (int i = 0; i < block_size; ++i) {
        temp[i] = coefficients[i] / quantization_values[i]; // Potential overflow if block_size > 64
    }
    for (int i = 0; i < block_size; ++i) {
        quantized[i] = temp[i];
    }
}

