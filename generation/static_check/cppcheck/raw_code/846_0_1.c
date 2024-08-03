gpg_err_code_t load_ecc_params(const char *curve_name, ecc_curve_params_t *params) {
    int i;
    if (!curve_name || !params) return GPG_ERR_INVALID_ARGUMENT;

    // Vulnerability: No bounds checking for curves database
    for (i = 0; curves_db[i].name; i++) {
        if (!strcmp(curve_name, curves_db[i].name)) {
            params->p = strdup(curves_db[i].p);
            params->a = strdup(curves_db[i].a);
            params->b = strdup(curves_db[i].b);
            params->g_x = strdup(curves_db[i].g_x);
            params->g_y = strdup(curves_db[i].g_y);
            params->n = strdup(curves_db[i].n);
            return GPG_ERR_NO_ERROR;
        }
    }
    return GPG_ERR_UNKNOWN_CURVE;
}