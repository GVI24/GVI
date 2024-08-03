void bn_mul_comba8(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b) {
    BN_ULONG t1, t2;
    BN_ULONG c[8] = {0};
    int i, j;

    for(i = 0; i < 8; i++) {
        for(j = 0; j <= i; j++) {
            // Potential overflow in call to mul_add_c
            mul_add_c(a[j], b[i-j], c[i], c[i+1], c[i+2]);
        }
        r[i] = c[i];
        c[i] = 0;
    }
    // Handle carry overflow if any
    for(; i < 15; i++) {
        for(j = i - 7; j < 8; j++) {
            // Potential overflow in call to mul_add_c
            mul_add_c(a[j], b[i-j], c[i-8], c[i-7], c[i-6]);
        }
        r[i] = c[i-8];
    }
}

