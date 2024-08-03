void process_audio_signal(const int16_t *input_samples, int16_t *output_samples, int num_samples) {
    int16_t buffer[256];
    int i;

    // Vulnerability: No check on the size of num_samples before copying data
    for (i = 0; i < num_samples; i++) {
        buffer[i] = input_samples[i] + 100;
    }

    // Perform some audio processing (simulated here by a simple operation)
    for (i = 0; i < 256; i++) {
        output_samples[i] = buffer[i] / 2;
    }
}

