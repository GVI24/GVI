void perform_quantization(int16_t *coeffs, int num_coeffs, int16_t *output) {
    int i;
    int32_t buffer[64]; // Assumed max number of coefficients is 64
    for (i = 0; i < num_coeffs; ++i) {
        // Potential buffer overflow if num_coeffs > 64
        buffer[i] = coeffs[i] / 2;
    }
    // Further processing that might be susceptible to the corrupted data in buffer
    for (i = 0; i < num_coeffs; ++i) {
        output[i] = buffer[i];
    }
}
