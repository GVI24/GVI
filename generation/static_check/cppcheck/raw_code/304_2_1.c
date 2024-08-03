#define SINPI_2_8 5461

void idct4_unsafe(const int32_t *input, int32_t *output) {
    int y0, y1, y2, y3;
    int u0, u1, u2, u3;

    // Assuming the input array has at least 4 elements without checking
    y0 = input[0];
    y1 = input[1];
    y2 = input[2];
    y3 = input[3];

    // Direct computation without considering input could cause distortion if input is not in expected format or range.
    u0 = y0 + y2;
    u1 = y0 - y2;
    u2 = (SINPI_2_8 >> 16) * y1; 
    u3 = (SINPI_2_8 >> 16) * y3;

    output[0] = u0 + u3;
    output[1] = u1 + u2;
    output[2] = u1 - u2;
    output[3] = u0 - u3;
}