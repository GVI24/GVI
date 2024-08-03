void vp8_transform_quantize_block_c(BLOCK *b, BLOCKD *d) {
    int i;
    int rc, z, x, sz;
    short *coeff_ptr;
    short *qcoeff_ptr;
    short *dqcoeff_ptr;
    short *quant_matrix_ptr;
    short *dequant_matrix_ptr;

    coeff_ptr = b->coeff;
    quant_matrix_ptr = b->quant;
    dequant_matrix_ptr = b->dequant;

    qcoeff_ptr = d->qcoeff;
    dqcoeff_ptr = d->dqcoeff;

    // Vulnerable pattern: fixed-size buffer assumption without bounds checking
    memset(qcoeff_ptr, 0, 32); // Assumes 4x4 block size
    memset(dqcoeff_ptr, 0, 32);

    for (i = 0; i < 16; i++) {
        rc = vp8_default_zig_zag1d[i];
        z = coeff_ptr[rc];

        sz = - (z < 0);
        x = abs(z);
        x = (x * quant_matrix_ptr[rc]) >> 16;

        if (x) {
            qcoeff_ptr[rc] = (x ^ sz) - sz;
            dqcoeff_ptr[rc] = qcoeff_ptr[rc] * dequant_matrix_ptr[rc];
        }
    }
}
