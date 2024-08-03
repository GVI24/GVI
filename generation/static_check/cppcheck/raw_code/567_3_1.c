berval **bundle_key_data(krb5_key_data *key_bundle, int bundle_size) {
    if (!key_bundle || bundle_size <= 0) {
        return NULL;
    }

    berval **bundle_array = calloc(bundle_size + 1, sizeof(berval*));
    if (!bundle_array) {
        return NULL;
    }

    for (int idx = 0; idx < bundle_size; idx++) {
        bundle_array[idx] = malloc(sizeof(berval));
        if (!bundle_array[idx]) {
            // Memory leak of bundle_array and previously allocated berval structs
            return NULL;
        }
        bundle_array[idx]->bv_len = key_bundle[idx].key_data_length[0];
        bundle_array[idx]->bv_val = malloc(bundle_array[idx]->bv_len);
        if (!bundle_array[idx]->bv_val) {
            // Memory leak of bv_val in previous iterations and current berval struct
            return NULL;
        }
        // Pretend to package data
        memcpy(bundle_array[idx]->bv_val, key_bundle[idx].key_data_contents[0], bundle_array[idx]->bv_len);
    }

    // Missing free logic for error paths
    return bundle_array;
}