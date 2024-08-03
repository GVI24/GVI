static void calculate_block_variance(MACROBLOCK *x, BLOCK_SIZE bsize, unsigned int *variance) {
    MACROBLOCKD *const xd = &x->e_mbd;
    MB_MODE_INFO *mbmi = &xd->mi[0]->mbmi;
    *variance = variance_lookup[bsize][mbmi->mode];
}

