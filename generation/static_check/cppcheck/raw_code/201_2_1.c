void decode_block(unsigned char *block, int block_size, const unsigned char *coefficients) {
    // Fixed-size stack buffer
    unsigned char decoded_output[64];
    // No bounds checking on 'block_size', can lead to stack buffer overflow
    for (int i = 0; i < block_size; ++i) {
        decoded_output[i] = block[i] + coefficients[i];
    }
    // Further processing...
}

