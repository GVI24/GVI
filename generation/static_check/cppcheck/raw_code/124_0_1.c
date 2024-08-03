static void apply_audio_filter(int *samples, int num_samples, int *filtered_output) {
    int filter_weights[3] = {1, -2, 1};
    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j <= 3; j++) { // Vulnerability: j should be < 3
            filtered_output[i] += samples[i + j] * filter_weights[j];
        }
    }
}

