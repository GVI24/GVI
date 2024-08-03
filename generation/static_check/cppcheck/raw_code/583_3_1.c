void spectral_data_synthesize(SynthesisContext *synth, float *spectral_data, int data_size) {
    // Vulnerability: No bounds check before buffer copy
    memcpy(synth->spectral_buffer, spectral_data, data_size * sizeof(float));
    // Use spectral data for synthesis processing
    // ...
    if (data_size > SPECTRAL_BUFFER_SIZE) {
        fprintf(stderr, "Spectral data size exceeds buffer capacity!\n");
        exit(EXIT_FAILURE);
    }
}