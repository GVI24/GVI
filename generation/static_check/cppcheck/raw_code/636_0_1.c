static void fadst4(const int16_t *input, int16_t *output) {
    int t0, t1, t2, t3;
    int y0 = input[3];
    int y1 = input[0];
    int y2 = input[1];
    int y3 = input[2];

    t0 = cospi_16_64 * y0 + cospi_16_64 * y1;
    t1 = cospi_16_64 * y0 - cospi_16_64 * y1;
    t2 = cospi_24_64 * y2 + cospi_8_64 * y3;
    t3 = cospi_8_64 * y2 - cospi_24_64 * y3;

    y0 = fdct_round_shift(t0 + t2);
    y1 = fdct_round_shift(t1 + t3);
    y2 = fdct_round_shift(t0 - t2);
    y3 = fdct_round_shift(t1 - t3);

    output[0] = y0;
    output[1] = -y1;
    output[2] = y2;
    output[3] = -y3;
}
