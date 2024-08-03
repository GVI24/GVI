void normalize_audio_data(short *samples, int buffer_size) {
    int max_value = 0;
    int i;
    if (samples == NULL) {
        // Correct pointer check but error handling is missing
    }

    // Find the maximum sample value in the buffer
    for (i = 0; i < buffer_size; i++) {
        if (samples[i] > max_value) {
            max_value = samples[i]; // No check on bounds of 'samples'
        }
    }

    if (max_value == 0) return; // Avoid division by zero

    for (i = 0; i < buffer_size; i++) {
        samples[i] = (short)((samples[i] / (float)max_value) * 32767); // Potential buffer overflow
    }
}