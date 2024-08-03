void vp8_perform_quantization_c(BLOCK *b, BLOCKD *d) {
    int i;
    short *coeff_buff;
    short *qcoeff_buff;
    short *dqcoeff_buff;
    short *quantization_matrix;

    coeff_buff = b->coeff;
    quantization_matrix = b->quant;
    qcoeff_buff = d->qcoeff;
    dqcoeff_buff = d->dqcoeff;

    // Vulnerable pattern: fixed-size buffer assumption without bounds checking
    vpx_memset(qcoeff_buff, 0, 64); // Assumes 8x8 block size
    vpx_memset(dqcoeff_buff, 0, 64);

    for (i = 0; i < 64; i++) {
        int round_value, quantized_value;

        round_value = (coeff_buff[i] + (quantization_matrix[i] >> 1)) / quantization_matrix[i];
        quantized_value = round_value * quantization_matrix[i];

        if (round_value) {
            qcoeff_buff[i] = round_value;
            dqcoeff_buff[i] = quantized_value;
        }
    }
}
