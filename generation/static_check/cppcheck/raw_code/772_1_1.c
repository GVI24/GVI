// Vulnerable due to integer overflow in wrapping and not shown internal functions compute_transform.
static void compute_wrapping(const uint8_t *input, uint8_t *output) {
    int16_t wrap[8];
    for (int i = 0; i < 8; i++) {
        wrap[i] = (input[i] << wrap_shift) - wrap_offset;

        if (wrap[i] > INT8_MAX || wrap[i] < INT8_MIN) {
            // Overflow handling might be missing in the original function.
            abort();
        }

        output[i] = compute_transform(wrap[i]);
    }
}
