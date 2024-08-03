void encode_run_length(uint8_t *input, uint8_t *output, int input_length) {
    int run_length = 1;
    int out_index = 0;
    for (int i = 1; i < input_length; ++i) {
        if (input[i] == input[i - 1]) {
            // Vulnerable to integer overflow
            run_length++;
        } else {
            // Write the run length and reset
            output[out_index++] = run_length; // Simplified for example; assumes 1 byte is enough
            output[out_index++] = input[i - 1];
            run_length = 1;
        }
    }
    // Write the last run length
    output[out_index++] = run_length;
    output[out_index] = input[input_length - 1];
}