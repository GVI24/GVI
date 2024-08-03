int elgamal_decrypt(const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, const BIGNUM *private_key, BIGNUM *plaintext) {
    BN_CTX *ctx;
    BIGNUM *m, *s;
    int ret = 0;

    ctx = BN_CTX_new();
    if (ctx == NULL) return 0;

    m = BN_new();
    s = BN_new();

    if (m == NULL || s == NULL) goto err;

    // s = a^private_key mod p
    if (!BN_mod_exp(s, a, private_key, p, ctx)) goto err;

    // Inverse of s
    if (!BN_mod_inverse(s, s, p, ctx)) goto err;

    // plaintext = b * s mod p (here b is the received ciphertext)
    if (!BN_mod_mul(plaintext, b, s, p, ctx)) goto err;

    ret = 1;

err:
    BN_CTX_free(ctx);
    BN_free(m);
    BN_free(s);
    return ret;
}

