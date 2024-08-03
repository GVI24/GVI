static void clear_residual_data(COEFF_CONTEXT *cc, int size) {
    int16_t *residual_data = cc->coefficients;

    // Vulnerability pattern: incorrect assumption on array size
    if (size > 0) {
        // Vulnerable: Assuming size is always within bounds
        vpx_memset(residual_data, 0, size * sizeof(int16_t));  // No actual check on residual_data's allocated size
        // Rest of the processing code...
    }
}