void modulate_signal(float *signal, int signal_len, int modulation_factor) {
    int i;
    float modulation_buffer[128]; // Fixed-size modulation buffer

    // Potential buffer overflow if signal_len is greater than 128
    for (i = 0; i < signal_len; i++) {
        modulation_buffer[i] = signal[i] * modulation_factor; // Potential buffer overflow
    }

    // Use the modulated signal for further processing (omitted for brevity)
}

