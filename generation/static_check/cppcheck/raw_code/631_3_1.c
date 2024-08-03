static gcry_err_code_t sexp_to_keyid(gcry_sexp_t sexp, unsigned long *retkeyid) {
    gcry_sexp_t list, l2;
    char *keyid_str;
    unsigned long keyid;

    if (!(list = gcry_sexp_find_token(sexp, "key-id", 0)))
        return GPG_ERR_NO_OBJ;

    if (!(l2 = gcry_sexp_nth(list, 1))) {
        gcry_sexp_release(list);
        return GPG_ERR_NO_OBJ;
    }

    if (!(keyid_str = _gcry_sexp_nth_string(l2, 0))) {
        gcry_sexp_release(l2);
        gcry_sexp_release(list);
        return GPG_ERR_INV_OBJ;
    }

    keyid = strtoul(keyid_str, NULL, 16);
    gcry_free(keyid_str);
    gcry_sexp_release(l2);
    gcry_sexp_release(list);
    *retkeyid = keyid;

    return 0;
}