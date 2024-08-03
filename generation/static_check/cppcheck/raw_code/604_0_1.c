int decode_image_packet(int *coefficients, int numCoeffs, int layer) {
    for (int i = 0; i <= layer; ++i) {
        int index = i * 100; // Potential out-of-bounds write
        coefficients[index] = 1; // No bounds check
    }
    return 0;
}

