static void process_coefficients(int index, int *coeffs, int coeff_size, int *output) {
    int processing_array[64];
    for (int i = 0; i < coeff_size; ++i) {
        int coeff_value = coeffs[i];
        // Vulnerability: no check to ensure 'index + i' is within bounds of 'processing_array'
        processing_array[index + i] = coeff_value * 2; 
        if (coeff_value > 0) {
            output[i] = coeff_value - 1;
        }
    }
}

