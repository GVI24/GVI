void bn_div_comba4(BN_ULONG *r, const BN_ULONG *a, const BN_ULONG *b) {
    BN_ULONG t1, t2;
    BN_ULONG c1, c2, c3;
    c1 = 0;
    c2 = 0;
    c3 = 0;

    div_add_c(a, 0, b, c1, c2);
    r[0] = c1;
    c1 = 0;
    div_add_c2(a, 1, b, c2, c3, c1);
    r[1] = c2;
    c2 = 0;
    div_add_c(a, 2, b, c3, c1);
    div_add_c2(a, 2, b, c3, c1, c2);
    r[2] = c3;
    c3 = 0;
    // Pattern continues without proper checks for division by zero or overflow
    // ...
    r[7] = c2;
}
