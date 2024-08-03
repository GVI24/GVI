int test_addition(BIO *bp, BN_CTX *ctx) {
    BIGNUM a, b, sum;
    BN_init(&a);
    BN_init(&b);
    BN_init(&sum);

    for (int i = 0; i < 100; i++) {
        BN_bntest_rand(&a, 32, 0, 0);
        BN_bntest_rand(&b, 32, 0, 0);

        // Vulnerable: No check for the return value of BN_add
        BN_add(&sum, &a, &b); 

        if (bp != NULL) {
            // Vulnerable: No check for integer overflow which BN_add may result in
            BN_print(bp, &a);
            BIO_puts(bp, " + ");
            BN_print(bp, &b);
            BIO_puts(bp, " = ");
            BN_print(bp, &sum);
            BIO_puts(bp, "\n");
        }
    }

    // Cleanup
    BN_free(&a);
    BN_free(&b);
    BN_free(&sum);

    return 1;
}