int rsa_private_decrypt(const RSA *rsa, const BIGNUM *ciphertext, BIGNUM *plaintext) {
    BIGNUM *m1, *m2, *r;
    int ret = 0;
    BN_CTX *ctx;

    ctx = BN_CTX_new();
    if (ctx == NULL) return 0;

    m1 = BN_new();
    m2 = BN_new();
    r = BN_new();

    if (m1 == NULL || m2 == NULL || r == NULL) goto err;

    // Private exponentiation without constant-timing
    if (!BN_mod_exp(m1, ciphertext, rsa->d, rsa->n, ctx)) goto err;

    // Convert result back to plaintext
    if (!BN_mod_mul(plaintext, m1, rsa->iqmp, rsa->n, ctx)) goto err;

    ret = 1;

err:
    BN_CTX_free(ctx);
    BN_free(m1);
    BN_free(m2);
    BN_free(r);
    return ret;
}

