void process_audio_samples(short *samples, int num_samples, const short *filter) {
    short processed[4096];
    memcpy(processed, samples, num_samples * sizeof(short)); // No bounds check on num_samples
    for (int i = 0; i < num_samples; i++) {
        processed[i] = (processed[i] + filter[i % 8]) / 2; // Simplified filter application
    }
    // Use the processed samples...
}

