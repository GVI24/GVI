int test_division(BIO *bp, BN_CTX *ctx) {
    BIGNUM numerator, denominator, result;
    BN_init(&numerator);
    BN_init(&denominator);
    BN_init(&result);

    BN_bntest_rand(&denominator, 64, 0, 0); // Vulnerable: random value may be zero
    BN_bntest_rand(&numerator, 128, 0, 0);

    // Vulnerable: No check if denominator is zero before division
    BN_div(&result, NULL, &numerator, &denominator, ctx); 

    // Vulnerable: No check for return value of BN_div
    if (bp != NULL) {
        BN_print(bp, &numerator);
        BIO_puts(bp, " / ");
        BN_print(bp, &denominator);
        BIO_puts(bp, " = ");
        BN_print(bp, &result);
        BIO_puts(bp, "\n");
    }

    // Cleanup
    BN_free(&numerator);
    BN_free(&denominator);
    BN_free(&result);

    return 1;
}

