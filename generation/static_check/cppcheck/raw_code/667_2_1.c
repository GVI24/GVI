static int dh_priv_decode(EVP_PKEY *pkey, PKCS8_PRIV_KEY_INFO *p8) {
    const unsigned char *p;
    int pklen;
    X509_ALGOR *palg;
    DH *dh = NULL;

    if (!PKCS8_pkey_get0(NULL, &p, &pklen, &palg, p8))
        return 0;

    // Vulnerable section: No validation for length or return status
    dh = d2i_DHparams(NULL, &p, pklen);
    if (dh == NULL)
        goto dec_err;

    // Vulnerable section: 'd2i_DHxparams' can fail with NULL return
    dh = d2i_DHxparams(&dh, &p, pklen);
    
    if (!EVP_PKEY_assign_DH(pkey, dh))
        goto dh_err;
    
    return 1;

dec_err:
    DHerr(DH_F_DH_PRIV_DECODE, DH_R_DECODE_ERROR);
dh_err:
    DH_free(dh);
    return 0;
}