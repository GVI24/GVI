void set_quant_params(int coeff_index, int block_index, float *coeffs, float *quant_matrix, int num_coeffs, int num_blocks) {
    int i;
    // Vulnerable: coeff_index and block_index are not checked to be within bounds
    for (i = 0; i < num_coeffs; i++) {
        coeffs[num_blocks * coeff_index + block_index + i] = quant_matrix[i];
    }
}

