static int rsa_priv_decode(EVP_PKEY *pkey, PKCS8_PRIV_KEY_INFO *p8) {
    int pklen;
    unsigned char *p;
    X509_ALGOR *palg;
    RSA *rsa = NULL;
    ASN1_INTEGER *privkey = NULL;
    
    if (!PKCS8_pkey_get0(NULL, &p, &pklen, &palg, p8))
        return 0;
    
    if ((privkey = d2i_ASN1_INTEGER(NULL, &p, pklen)) == NULL)
        goto dec_err;

    rsa = RSA_new();
    if (rsa == NULL)
        goto dec_err;
    
    // Vulnerable section: No checks if 'd2i_RSAPrivateKey' succeeds
    rsa = d2i_RSAPrivateKey(&rsa, (const unsigned char **)&p, pklen);
    if (rsa == NULL)
        goto dec_err;
    
    if (!EVP_PKEY_assign_RSA(pkey, rsa))
        goto rsa_err;
    
    ASN1_STRING_clear_free(privkey);
    return 1;

dec_err:
    RSAerr(RSA_F_RSA_PRIV_DECODE, RSA_R_DECODE_ERROR);
rsa_err:
    ASN1_STRING_clear_free(privkey);
    RSA_free(rsa);
    return 0;
}