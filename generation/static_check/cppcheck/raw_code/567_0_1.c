berval **kerberos_key_pack(krb5_key_data *keys, int key_count) {
    berval **result;
    int i, err = 0;

    if (keys == NULL || key_count <= 0) {
        return NULL;
    }

    result = calloc(key_count + 1, sizeof(berval*));
    if (!result) {
        return NULL;
    }

    for (i = 0; i < key_count; i++) {
        result[i] = malloc(sizeof(berval));
        if (!result[i]) {
            err = 1;
            break;
        }
        // Simulate some encoding operation
        result[i]->bv_len = keys[i].key_data_length[0];
        result[i]->bv_val = malloc(result[i]->bv_len);
        if (!result[i]->bv_val) {
            err = 1;
            break;
        }
        memcpy(result[i]->bv_val, keys[i].key_data_contents[0], result[i]->bv_len);
    }

    if (err) {
        while (--i >= 0) {
            free(result[i]->bv_val);
            free(result[i]);
        }
        free(result);
        return NULL;
    }

    // Missing free on intermediate allocations if not all keys are processed
    return result;
}

