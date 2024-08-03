static void transform8(int16_t *data) {
    extern int cospi_A, cospi_B; // Not initialized within this function
    int s0, s1;

    if (!data) return; // Check for NULL but not for data content

    s0 = cospi_A * data[0];
    s1 = cospi_B * data[7];

    // Combined input and computation, potential for incorrect results if cospi_A or cospi_B are not set correctly
    data[0] = s0 + s1;
    data[7] = s0 - s1;
    // Rest of transformation logic...
}