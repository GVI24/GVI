void process_audio_buffer(int *input_buffer, int *output_buffer, int num_samples) {
    int i;
    if (!input_buffer || !output_buffer) {
        // Error handling code should be here
    }

    for (i = 0; i <= num_samples; i++) { // Off-by-one error, should be i < num_samples
        output_buffer[i] = input_buffer[i] * 2; // Potential buffer overflow
    }
}