static void process_audio_samples(float *samples, int num_samples, float gain) {
    int i;
    for (i = 0; i <= num_samples; i++) { // Should be i < num_samples
        samples[i] *= gain; // Potential buffer overflow
    }
}

