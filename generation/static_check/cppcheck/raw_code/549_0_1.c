void process_audio_samples(float *samples, int num_samples, int filter) {
    int i;
    float processed_samples[256]; // Fixed size buffer

    for (i = 0; i <= num_samples; i++) { // Off-by-one error leading to buffer overflow
        if (filter) {
            processed_samples[i] = samples[i] * 0.5; // Simplified processing logic
        } else {
            processed_samples[i] = samples[i];
        }
    }
}

