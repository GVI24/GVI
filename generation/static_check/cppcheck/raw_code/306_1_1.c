int test_modulo(BIO *bp, BN_CTX *ctx) {
    BIGNUM a, b, result;
    int rand_val;

    BN_init(&a);
    BN_init(&b);
    BN_init(&result);

    for (int i = 0; i < 100; i++) {
        BN_bntest_rand(&a, 128, 0, 0);
        rand_val = rand_range(128); // Vulnerable: Unchecked external input
        BN_set_word(&b, rand_val);
        BN_mod(&result, &a, &b, ctx);

        if (bp != NULL) {
            // Vulnerable: Potential buffer overflow with BIO_puts
            BN_print(bp, &a);
            BIO_puts(bp, " % ");
            BN_print(bp, &b);
            BIO_puts(bp, " = ");
            BN_print(bp, &result);
            BIO_puts(bp, "\n");
        }
    }

    // Cleanup
    BN_free(&a);
    BN_free(&b);
    BN_free(&result);

    return 1;
}

