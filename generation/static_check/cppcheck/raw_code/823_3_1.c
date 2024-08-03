static int adjust_noise_floor(float *noise_levels, int num_levels, float adjustment_factor) {
    for (int i = 0; i <= num_levels; i++) { // Incorrect loop condition can cause buffer overrun
        if (i == num_levels) {
            printf("Error: Noise level array index out of bounds\n");
            return -1;
        }
        noise_levels[i] *= adjustment_factor;
    }
    //... (further processing)
    return 0;
}