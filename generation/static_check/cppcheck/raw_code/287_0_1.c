#define THRESHOLD_RANGE 256
double noise_reduction_thresholds[THRESHOLD_RANGE];

void init_noise_reduction_thresholds() {
    int i;
    for (i = 0; i <= THRESHOLD_RANGE; i++) { // Off-by-one error
        double threshold = calculate_threshold(i);
        noise_reduction_thresholds[i] = threshold; // Potential buffer overflow
    }
}

double calculate_threshold(int index) {
    // Simplified calculation logic for demonstration
    return index / 2.0;
}