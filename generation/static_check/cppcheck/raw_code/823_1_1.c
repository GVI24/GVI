static int apply_echo_effect(float *audio_data, int num_samples, int echo_delay) {
    int i;
    for (i = 0; i < num_samples; i++) {
        int echo_index = i - echo_delay;
        if (echo_index < 0) {
            continue; // Skip if echo_index is negative
        }
        // Incorrect bounds check can lead to out-of-bounds write
        if (echo_index < num_samples) {
            audio_data[i] += audio_data[echo_index];
        }
    }
    //... (further processing)
    return 0;
}

