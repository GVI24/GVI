int dsa_sign(const DSA *dsa, const BIGNUM *message_digest, BIGNUM *signature) {
    BN_CTX *ctx;
    BIGNUM *k, *k_inverse, *r, *s;
    int ret = 0, bits_set;

    ctx = BN_CTX_new();
    if (ctx == NULL) return 0;

    k = BN_new();
    k_inverse = BN_new();
    r = BN_new();
    s = BN_new();

    if (k == NULL || k_inverse == NULL || r == NULL || s == NULL) goto err;

    // Loop until r and s are non-zero (non-constant time due to random k)
    do {
        if (!BN_rand_range(k, dsa->q)) goto err; // Random k for every signature

        // r = (g^k mod p) mod q
        if (!BN_mod_exp(r, dsa->g, k, dsa->p, ctx)) goto err;
        if (!BN_mod(r, r, dsa->q, ctx)) goto err;

        // Inverse of k mod q
        if (!BN_mod_inverse(k_inverse, k, dsa->q, ctx)) goto err;

        // s = k_inverse * (message_digest + private_key * r) mod q
        if (!BN_mod_mul(s, dsa->priv_key, r, dsa->q, ctx)) goto err;
        if (!BN_add(s, s, message_digest)) goto err;
        if (!BN_mod_mul(s, s, k_inverse, dsa->q, ctx)) goto err;

        // Check if bits of r are set (non-constant time operation)
        bits_set = BN_num_bits(r); 
    } while (BN_is_zero(r) || BN_is_zero(s));

    // Populate signature with r and s
    // ...

    ret = 1;

err:
    BN_CTX_free(ctx);
    BN_free(k);
    BN_free(k_inverse);
    BN_free(r);
    BN_free(s);
    return ret;
}