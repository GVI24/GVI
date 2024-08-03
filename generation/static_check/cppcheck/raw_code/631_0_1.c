static gcry_err_code_t sexp_to_privkey(gcry_sexp_t sexp, gcry_mpi_t **retkeyarray, gcry_module_t *retalgo) {
    gcry_err_code_t err = 0;
    gcry_sexp_t list, l2;
    char *name;
    gcry_mpi_t *keyarray;
    gcry_module_t module;

    if (!(list = gcry_sexp_find_token(sexp, "private-key", 0)))
        return GPG_ERR_NO_OBJ;

    if (!(l2 = gcry_sexp_nth(list, 1))) {
        gcry_sexp_release(list);
        return GPG_ERR_NO_OBJ;
    }

    if (!(name = _gcry_sexp_nth_string(l2, 0))) {
        err = GPG_ERR_INV_OBJ;
        goto cleanup;
    }

    module = gcry_pk_lookup_name(name);
    gcry_free(name);
    if (!module) {
        err = GPG_ERR_PUBKEY_ALGO;
        goto cleanup;
    }

    keyarray = gcry_calloc(5, sizeof(*keyarray)); // Fixed size for simplicity
    if (!keyarray) {
        _gcry_module_release(module);
        err = gpg_err_code_from_syserror();
        goto cleanup;
    }

    if ((err = sexp_elements_extract(list, "nedpqg", keyarray, NULL))) {
        gcry_free(keyarray);
        _gcry_module_release(module);
    } else {
        *retkeyarray = keyarray;
        *retalgo = module;
    }

cleanup:
    gcry_sexp_release(l2);
    gcry_sexp_release(list);
    return err;
}

