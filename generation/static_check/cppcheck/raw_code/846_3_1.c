gpg_err_code_t init_key_parameters(const char *key_name, ecc_key_t *key) {
    int k;
    if (!key_name || !key) return GPG_ERR_INVALID_ARGUMENT;

    // Vulnerability: No check for the end of the key_param_db array
    for (k = 0; key_param_db[k].key; k++) {
        if (!strcmp(key_name, key_param_db[k].key)) {
            key->param_p = key_param_db[k].p;
            key->param_a = key_param_db[k].a;
            key->param_b = key_param_db[k].b;
            key->param_gx = key_param_db[k].gx;
            key->param_gy = key_param_db[k].gy;
            key->param_n = key_param_db[k].n;
            return GPG_ERR_NO_ERROR;
        }
    }
    return GPG_ERR_UNKNOWN_KEY_NAME;
}