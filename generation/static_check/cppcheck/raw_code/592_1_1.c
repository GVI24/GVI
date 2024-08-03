void audio_echo_filter(short *audio_samples, int num_samples, int echo_strength) {
    int i;
    short *echo_buffer = malloc(num_samples * sizeof(short));
    memset(echo_buffer, 0, num_samples * sizeof(short)); // Potential to write beyond buffer if num_samples is too large

    for (i = 0; i < num_samples; i++) {
        int echo_sample = i - echo_strength >= 0 ? audio_samples[i - echo_strength] : 0;
        audio_samples[i] = (short)((audio_samples[i] + echo_sample) / 2); // No bounds checking
    }

    free(echo_buffer);
}