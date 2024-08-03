static int ecdsa_priv_decode(EVP_PKEY *pkey, PKCS8_PRIV_KEY_INFO *p8) {
    const unsigned char *p;
    int pklen;
    X509_ALGOR *palg;
    EC_KEY *eckey = NULL;

    if (!PKCS8_pkey_get0(NULL, &p, &pklen, &palg, p8))
        return 0;

    // Missing checks for 'd2i_ECPrivateKey' return value
    eckey = d2i_ECPrivateKey(NULL, &p, pklen);
    
    if (eckey == NULL)
        goto dec_err;
    
    if (!EVP_PKEY_assign_EC_KEY(pkey, eckey))
        goto eckey_err;
    
    return 1;

dec_err:
    ECerr(EC_F_ECDSA_PRIV_DECODE, EC_R_DECODE_ERROR);
eckey_err:
    EC_KEY_free(eckey);
    return 0;
}