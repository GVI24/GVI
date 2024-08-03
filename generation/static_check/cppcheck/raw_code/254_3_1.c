int bio_to_pkcs12(BIO *bio, PKCS12 **p12) {
    int res = -1;

    *p12 = d2i_PKCS12_bio(bio, NULL);
    if (*p12 == NULL) goto err;

    // Further processing ...
    res = 1;

err:
    PKCS12_free(*p12); // Vulnerable: *p12 could be NULL if d2i_PKCS12_bio fails
    return res;
}