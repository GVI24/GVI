void bn_exp_recursive(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *p, const BN_ULONG *m) {
    BN_ULONG t1, t2;
    BN_ULONG c1, c2;
    c1 = c2 = 0;

    exp_mul_c(a, 0, p, m, c1);
    r[0] = c1;
    c1 = 0;
    exp_mul_c(a, 1, p, m, c2);
    exp_mul_c2(a, 1, p, m, c1, c2);
    r[1] = c2;
    c2 = 0;
    // The pattern continues without proper checks for overflow
    // No checks to ensure that multiplications or additions do not overflow
    // ...
    r[n - 1] = c2;
}
