#define MAX_COEFFS 1024

void calculate_quantization(int *coeffs, int num_coeffs, int scale_factor) {
    long quantized_coeffs[MAX_COEFFS];

    // Vulnerable: Integer overflow when scale_factor is large
    for (int i = 0; i < num_coeffs; i++) {
        quantized_coeffs[i] = coeffs[i] * scale_factor;
    }

    // Further processing...
}

// Usage of the function that could cause integer overflow
void encode_block() {
    int block_coeffs[MAX_COEFFS];
    // Populate block_coeffs with values
    // Vulnerable if scale_factor is too high, causing overflow when multiplied
    calculate_quantization(block_coeffs, MAX_COEFFS, 1000000);
}