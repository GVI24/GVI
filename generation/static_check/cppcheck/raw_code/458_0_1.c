void bn_mul_comba8(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b) {
    BN_ULONG t1, t2;
    BN_ULONG c1, c2, c3, c4, c5, c6;
    c1 = c2 = c3 = c4 = c5 = c6 = 0;

    mul_add_c(a, 0, b, 0, c1, c2);
    r[0] = c1;
    c1 = 0;
    mul_add_c2(a, 1, b, 0, c2, c3, c1);
    mul_add_c2(a, 0, b, 1, c2, c3, c1);
    r[1] = c2;
    c2 = 0;
    mul_add_c(a, 2, b, 0, c3, c4);
    mul_add_c2(a, 1, b, 1, c3, c4, c1);
    mul_add_c2(a, 0, b, 2, c3, c4, c1);
    r[2] = c3;
    c3 = 0;
    // The pattern continues without proper checks for overflow
    // ...
    r[14] = c6;
    r[15] = c5; // Potentially c5 can overflow from previous operations
}
