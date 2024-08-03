static void normalize_audio_samples(AUDIO_BUFFER *audioBuffer, int16_t normalizeValue) {
    int i;
    int16_t *samples = audioBuffer->samples;
    for (i = 0; i < audioBuffer->num_samples; i++) {
        if (samples[i] > normalizeValue) {
            samples[i] = normalizeValue;
        }
        // No check for 'num_samples' boundary which might lead to buffer overflow
    }
}

