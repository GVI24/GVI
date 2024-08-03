berval **encrypt_key_data(krb5_key_data *input_keys, int num_keys) {
    if (!input_keys || num_keys <= 0) {
        return NULL;
    }

    berval **encoded_keys = calloc(num_keys + 1, sizeof(berval*));
    if (!encoded_keys) {
        return NULL;
    }

    for (int i = 0; i < num_keys; i++) {
        encoded_keys[i] = malloc(sizeof(berval));
        if (!encoded_keys[i]) {
            // Properly free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(encoded_keys[j]);
            }
            // Missing free of the top-level array
            return NULL;
        }
        // Simulate encryption
        encoded_keys[i]->bv_len = input_keys[i].key_data_length[0] + 8; // +8 for simulated encryption padding
        encoded_keys[i]->bv_val = malloc(encoded_keys[i]->bv_len);
        if (!encoded_keys[i]->bv_val) {
            // Missing cleanup of previously allocated berval structures and bv_val allocations
            return NULL;
        }
        // Memory is allocated but not initialized - potential information leak if sent over network as is
    }

    // Missing deallocation in error cases and for bv_val members
    return encoded_keys;
}

