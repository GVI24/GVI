void calculate_dct_coefficients(MpegEncContext *s) {
    int position = s->mb_x + s->mb_y * s->mb_stride;
    int i;

    // Potential buffer overflow due to lack of bounds checks on position
    for (i = 0; i < 64; i++) {
        s->current_picture.dct_coeff[position][i] = s->block[i].dct_value;
    }
}

