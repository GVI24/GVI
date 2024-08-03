static gcry_err_code_t sexp_to_keygrip(gcry_sexp_t sexp, unsigned char **retgrip) {
    gcry_sexp_t list;
    size_t grip_len;
    unsigned char *grip;

    if (!(list = gcry_sexp_find_token(sexp, "keygrip", 0)))
        return GPG_ERR_NO_OBJ;

    grip_len = 20; // Assume grip length is 20
    grip = gcry_malloc(grip_len);
    if (!grip) {
        gcry_sexp_release(list);
        return gpg_err_code_from_syserror();
    }

    if (gcry_sexp_extract_param(list, NULL, "%b", grip, grip_len)) {
        gcry_free(grip);
        gcry_sexp_release(list);
        return GPG_ERR_INTERNAL;
    }

    *retgrip = grip;
    gcry_sexp_release(list);
    return 0;
}

