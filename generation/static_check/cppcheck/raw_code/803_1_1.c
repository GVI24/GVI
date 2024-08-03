int process_audio_samples(int16_t *samples, int num_samples) {
    int16_t *buffer = (int16_t *)malloc(num_samples * sizeof(int16_t));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    for (int i = 0; i < num_samples; i++) {
        buffer[i] = samples[i];
    }

    // Simulate some processing...
    free(buffer);

    // Vulnerability: use-after-free, buffer is used after it has been freed.
    for (int i = 0; i < num_samples; i++) {
        samples[i] = buffer[i] + 1;
    }

    return 0;
}

