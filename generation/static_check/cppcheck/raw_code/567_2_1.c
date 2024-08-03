berval **duplicate_key_pack(krb5_key_data *src_keys, int count) {
    if (!src_keys || count <= 0) {
        return NULL;
    }

    berval **dup_keys = calloc(count + 1, sizeof(berval*));
    if (!dup_keys) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        dup_keys[i] = malloc(sizeof(berval));
        if (!dup_keys[i]) {
            // Missing free for dup_keys
            return NULL;
        }
        dup_keys[i]->bv_len = src_keys[i].key_data_length[0];
        dup_keys[i]->bv_val = strdup(src_keys[i].key_data_contents[0]);
        if (!dup_keys[i]->bv_val) {
            // Missing cleanup of previously allocated structures
            return NULL;
        }
    }

    return dup_keys;
}

