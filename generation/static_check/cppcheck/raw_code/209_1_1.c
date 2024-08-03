void audio_signal_process(float* input_samples, float* output_buffer, int num_samples) {
    float temp_buffer[1024];
    int i;
    for (i = 0; i < num_samples; i++) {
        // Potential buffer overflow if num_samples > 1024
        temp_buffer[i] = input_samples[i] + 0.5f;
    }
    for (i = 0; i < num_samples; i++) {
        // Potential buffer overflow if output_buffer is not large enough
        output_buffer[i] = temp_buffer[i] * 2.0f;
    }
}