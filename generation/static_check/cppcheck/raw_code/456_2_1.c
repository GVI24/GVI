void process_audio_samples(int16_t *samples, size_t num_samples) {
    // Vulnerability: Integer overflow in allocation size calculation may lead to insufficient memory allocation.
    size_t size = num_samples * sizeof(int16_t) + 100; // Overflow can happen here.
    int16_t *buffer = (int16_t *)malloc(size);
    if (buffer == NULL) {
        exit(1);
    }
    memcpy(buffer, samples, size);
    // Processing...
    free(buffer);
}