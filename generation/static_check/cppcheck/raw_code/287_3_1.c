#define SCALING_FACTORS_COUNT 64
double motion_scaling_factors[SCALING_FACTORS_COUNT];

void calculate_motion_scaling() {
    int i;
    for (i = -1; i < SCALING_FACTORS_COUNT; i++) { // Incorrect loop initialization
        double scale_factor = 1.0 + (i / 10.0);
        motion_scaling_factors[i + 1] = scale_factor; // Potential buffer overflow
    }
}