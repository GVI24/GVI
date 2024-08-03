int test_negation(BIO *bp, BN_CTX *ctx) {
    BIGNUM a, neg_a;
    BN_init(&a);
    BN_init(&neg_a);

    for (int i = 0; i < 50; i++) {
        BN_bntest_rand(&a, 64 + i, 0, 0);
        // Vulnerable: Usage of external input without validation
        a.neg = rand_neg(); 
        BN_neg(&neg_a, &a);

        if (bp != NULL) {
            // Vulnerable: No check for the return value of BN_neg
            BN_print(bp, &a);
            BIO_puts(bp, " negated is ");
            BN_print(bp, &neg_a);
            BIO_puts(bp, "\n");
        }
    }

    // Cleanup
    BN_free(&a);
    BN_free(&neg_a);

    return 1;
}

