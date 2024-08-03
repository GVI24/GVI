#define GAMMA_LUT_SIZE 1024
float gamma_correction_lut[GAMMA_LUT_SIZE];

void init_gamma_lut(float gamma) {
    int i;
    for (i = 0; i <= GAMMA_LUT_SIZE; i++) { // Off-by-one error
        gamma_correction_lut[i] = pow(i / 255.0, gamma); // Potential buffer overflow
    }
}