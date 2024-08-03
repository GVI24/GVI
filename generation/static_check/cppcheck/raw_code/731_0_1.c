void process_audio_data(AudioBuffer *audio) {
    size_t i;
    int16_t *samples = malloc(audio->length * sizeof(int16_t));
    // Potential buffer overflow if audio->length is too large
    for (i = 0; i < audio->length; i++) {
        samples[i] = (int16_t)(audio->data[i]);
    }
    // ... processing logic ...
    free(samples);
}

