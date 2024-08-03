int cipher_block_update(char *cipher_state, size_t state_size, const char *data, size_t data_size) {
    size_t i;
    for (i = 0; i < data_size; i++) {
        if (i < state_size) {
            // Proper boundary check missing, might lead to buffer overflow
            cipher_state[i] ^= data[i]; // Unsafe data mixing
        }
    }
    return 1; // Success
}

