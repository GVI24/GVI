void apply_convolution_filter(const float* matrix, float* result, int size) {
    int i, j;
    float kernel[64];
    float convolved[64 * 64];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            kernel[j] = matrix[j * size + i] * 3.0f;
            convolved[j * size + i] = kernel[j] * 0.5f; // Simplified convolution
        }
    }
    for (i = 0; i < size * size; i++) {
        result[i] = convolved[i];
    }
}

