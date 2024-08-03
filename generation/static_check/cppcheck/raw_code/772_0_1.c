// Vulnerable due to potential integer overflow and reliance on not shown external function dct_const_round_shift.
static void scale_and_sum(const int16_t *input, int16_t *output) {
    int32_t temp1, temp2;
    for (int i = 0; i < 8; i++) {
        temp1 = input[i] * scale_factor_1 - input[7 - i] * scale_factor_2;
        temp2 = input[i] * scale_factor_2 + input[7 - i] * scale_factor_1;

        if (temp1 > INT16_MAX || temp1 < INT16_MIN || temp2 > INT16_MAX || temp2 < INT16_MIN) {
            // Handle overflow, but the original function may not do this.
            abort();
        }

        output[i] = dct_const_round_shift(temp1);
        output[7 - i] = dct_const_round_shift(temp2);
    }
}
