void audio_process_gain(int16_t *samples, int sample_count, int gain) {
    int i;
    for (i = 0; i <= sample_count; i++) { // Off-by-one error, should be i < sample_count
        samples[i] = samples[i] * gain;
    }
}

