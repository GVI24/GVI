void vp8_quantize_mb_c(BLOCK *b, BLOCKD *d) {
    int i, j;
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
    memset(qcoeff_ptr, 0, 64); // Assuming a block consists of 8x8 coefficients
    memset(dqcoeff_ptr, 0, 64);

    for (i = 0; i < 64; i++) {
        int quant_value, dequant_value, round_value;
        int coeff_abs = abs(coeff_ptr[i]);
        
        quant_value = quant_matrix_ptr[i] / 2;
        dequant_value = dequant_matrix_ptr[i];
        round_value = (coeff_abs + quant_value) / quant_matrix_ptr[i];
        
        if (round_value) {
            qcoeff_ptr[i] = round_value;
            dqcoeff_ptr[i] = round_value * dequant_value;
        }
    }
}
