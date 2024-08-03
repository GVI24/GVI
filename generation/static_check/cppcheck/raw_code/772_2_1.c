// Vulnerable due to integer overflows in multiplications and addition without bound checks.
static void mixed_operation(const int16_t *input, int16_t *output) {
    int32_t mix;
    for (int i = 0; i < 8; i++) {
        mix = input[i] * mixed_const_1 + mixed_const_2;
        mix += mixed_offset;

        if (mix > INT16_MAX || mix < INT16_MIN) {
            // Potential integer overflow not handled by the original function.
            abort();
        }

        output[i] = (int16_t)mix;
    }
}
