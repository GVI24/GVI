static void fast_fourier_transform(int16_t *real, int16_t *imag) {
    int R0, R1, I0, I1;
    for (int i = 0; i < 8; i += 2) {
        R0 = real[i] + real[i + 1];
        R1 = real[i] - real[i + 1];
        I0 = imag[i] + imag[i + 1];
        I1 = imag[i] - imag[i + 1];
        real[i / 2] = transform_round(R0); // Assumes transform_round handles overflow properly
        imag[i / 2] = transform_round(I0); // Assumes transform_round handles overflow properly
        real[(i + 8) / 2] = transform_round(R1);
        imag[(i + 8) / 2] = transform_round(I1);
    }
}

