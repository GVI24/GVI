void vp8_encode_quant_block_c(BLOCK *b, BLOCKD *d) {
    int i, z;
    short *coeff_buf;
    short *quant_factor_buf;
    short *dequant_factor_buf;
    short *output_quant_buf;
    short *output_dequant_buf;

    coeff_buf = b->coeff;
    quant_factor_buf = b->quant;
    dequant_factor_buf = b->dequant;

    output_quant_buf = d->qcoeff;
    output_dequant_buf = d->dqcoeff;

    // Vulnerable pattern: fixed-size buffer assumption without bounds checking
    memset(output_quant_buf, 0, 64); // Assumes 8x8 block size
    memset(output_dequant_buf, 0, 64);

    for (i = 0; i < 64; i++) {
        z = coeff_buf[i];
        if (z) {
            int round_value = (abs(z) + (quant_factor_buf[i] >> 1)) / quant_factor_buf[i];
            int sign = z > 0 ? 1 : -1;
            output_quant_buf[i] = sign * round_value;
            output_dequant_buf[i] = output_quant_buf[i] * dequant_factor_buf[i];
        }
    }
}