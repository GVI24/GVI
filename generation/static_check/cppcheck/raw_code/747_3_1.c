void equalize_sound(int *sound_samples, int num_samples, int *equalization_curve) {
    int i;
    int equalized_samples[512]; // Fixed-size array for equalized samples

    // Assuming num_samples will not exceed 512 without validation
    for (i = 0; i < num_samples; i++) {
        // Potential buffer overflow as there's no check if i is within array bounds
        equalized_samples[i] = sound_samples[i] * equalization_curve[i]; // Potential buffer overflow
    }

    // Processing the equalized samples (omitted for brevity)
}