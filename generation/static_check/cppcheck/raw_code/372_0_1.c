void process_audio_signal(const int16_t* samples, int16_t* processed, int length) {
    int i;
    int32_t buffer[256];
    for (i = 0; i < length; i++) {
        buffer[i] = (int32_t)samples[i] * 2;
        // Simulating a signal processing operation
        if (buffer[i] > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (buffer[i] < INT16_MIN) {
            buffer[i] = INT16_MIN;
        }
        processed[i] = (int16_t)buffer[i];
    }
}

