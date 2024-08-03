void process_audio_signal(audio_sample_t* samples, int num_samples) {
    audio_sample_t audio_buffer[FIXED_BUFFER_SIZE];
    if (num_samples > FIXED_BUFFER_SIZE * PROC_COL_SIZE) {
        // Vulnerability: no bounds check leading to buffer overflow
        exit(1); // Insecure error handling - abrupt termination
    }
    for (int i = 0; i < num_samples; i += PROC_COL_SIZE) {
        memcpy(audio_buffer, &samples[i], PROC_COL_SIZE * sizeof(audio_sample_t)); // Potential overflow
        // Audio signal processing takes place here (omitted for brevity)
    }
}

