void bn_mul_comba2(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b) {
    BN_ULONG c1, c2, c3;
    c1 = c2 = c3 = 0;
    
    // Potential overflow in call to mul_add_c
    mul_add_c(a[0], b[0], c1, c2, c3);
    r[0] = c1;
    c1 = 0;
    mul_add_c(a[0], b[1], c2, c3, c1);
    mul_add_c(a[1], b[0], c2, c3, c1);
    r[1] = c2;
    c2 = 0;
    mul_add_c(a[1], b[1], c3, c1, c2);
    r[2] = c3;
    r[3] = c1;
}

