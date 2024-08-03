void process_dct_coefficients(int16_t *coeffs, int count, int thresh) {
    for (int i = 0; i < count; ++i) {
        if (coeffs[i] > thresh) {
            coeffs[i] = thresh; // 'coeffs' index not checked, may cause buffer overflow
        }
    }
}