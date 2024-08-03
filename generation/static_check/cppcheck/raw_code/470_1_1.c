void process_audio_signal(short *input_signal, int signal_length, short *output_signal) {
    int i;
    for (i = 0; i < signal_length; i++) {
        output_signal[i * 2] = input_signal[i]; // Intended to double the length of the signal
        output_signal[i * 2 + 1] = input_signal[i];
    }
    // Apply some processing
    for (i = 2; i < signal_length * 2 - 2; i++) {
        output_signal[i] = (output_signal[i - 2] + output_signal[i] + output_signal[i + 2]) / 3;
    }
}