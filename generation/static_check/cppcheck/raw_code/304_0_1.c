#define COSPI_1_8 362
#define COSPI_3_8 -513

static void fdct4(const int16_t *input, int16_t *output) {
    int x0, x1, x2, x3;
    int t0, t1, t2, t3;

    // No input validation performed here
    x0 = input[0];
    x1 = input[1];
    x2 = input[2];
    x3 = input[3];

    t0 = COSPI_1_8 * (x0 + x3);
    t1 = COSPI_3_8 * (x0 - x3);
    t2 = COSPI_1_8 * (x1 + x2);
    t3 = COSPI_3_8 * (x1 - x2);

    output[0] = (t0 + t2);
    output[1] = (t1 + t3);
    output[2] = (t0 - t2);
    output[3] = (t1 - t3);
}