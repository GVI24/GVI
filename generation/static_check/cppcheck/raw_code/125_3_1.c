void bn_add_comba4(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b) {
    BN_ULONG c = 0;
    int i;

    for(i = 0; i < 4; i++) {
        // Potential overflow in add operation
        r[i] = a[i] + b[i] + c;
        // Simplistic carry determination, potentially incorrect
        c = (r[i] < a[i] || (r[i] == a[i] && c != 0)) ? 1 : 0;
    }
    r[4] = c;
}