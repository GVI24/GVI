void audio_process_gain(int *samples, int num_samples, int gain_factor) {
    for (int i = 0; i < num_samples; ++i) {
        // Vulnerable to integer overflow
        int temp = samples[i] * gain_factor;
        samples[i] = (temp > INT16_MAX) ? INT16_MAX : ((temp < INT16_MIN) ? INT16_MIN : temp);
    }
}
