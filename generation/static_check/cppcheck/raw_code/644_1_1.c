void transform_coeffs(const int16_t* coeffs, int16_t* transformed, const int16_t* scan_order, int num_coeffs) {
    for (int i = 0; i < num_coeffs; i++) {
        int pos = scan_order[i]; // Vulnerability: No bounds checking for 'scan_order[i]'
        transformed[pos] = coeffs[pos] * 2; // Vulnerability: Possible buffer overflow
    }
}

