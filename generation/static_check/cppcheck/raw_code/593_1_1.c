void compute_wavelet(int16_t *input, int16_t *output) {
    int s[8];
    for (int i = 0; i < 8; i++) {
        // Constants wavelet_coeff_* are assumed to be defined and correct
        s[i] = input[i] * wavelet_coeff_i + input[7 - i] * wavelet_coeff_7_i;
        output[i] = round_shift(s[i]);
    }
}

