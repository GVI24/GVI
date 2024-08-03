static gcry_err_code_t sexp_to_pubkey(gcry_sexp_t sexp, gcry_mpi_t **retcomp) {
    gcry_err_code_t err = 0;
    gcry_sexp_t list;
    char *name;
    gcry_mpi_t *comps;

    if (!(list = gcry_sexp_find_token(sexp, "public-key", 0)))
        return GPG_ERR_NO_OBJ;

    if (!(name = _gcry_sexp_nth_string(list, 1))) {
        gcry_sexp_release(list);
        return GPG_ERR_NO_OBJ;
    }

    comps = gcry_calloc(3, sizeof(*comps)); // Assume 3 components
    if (!comps) {
        gcry_free(name);
        gcry_sexp_release(list);
        return gpg_err_code_from_syserror();
    }

    err = sexp_elements_extract(list, "ne", comps, NULL);
    gcry_free(name);
    if (err) {
        gcry_free(comps);
    } else {
        *retcomp = comps;
    }
    gcry_sexp_release(list);
    return err;
}

