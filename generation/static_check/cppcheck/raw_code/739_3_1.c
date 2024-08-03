void add_echo_effect(float *audio_in, float *audio_out, int sample_rate, int delay_ms, float decay) {
    int i, delay_samples = (sample_rate * delay_ms) / 1000;
    if (audio_in == NULL || audio_out == NULL) {
        // Error handling should be present here
    }

    for (i = 0; i < delay_samples; i++) {
        // Copy initial samples without echo
        audio_out[i] = audio_in[i]; // Potential buffer overflow if 'audio_out' is smaller
    }

    while (i < (sample_rate * 60)) { // Let's say we process up to a minute of audio
        // Add echo effect - can write beyond the buffers if sizes are not validated
        audio_out[i] = (audio_in[i] + decay * audio_out[i - delay_samples]);
        i++;
    }
}