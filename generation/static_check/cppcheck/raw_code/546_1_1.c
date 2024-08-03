void process_audio_samples(int sample_index, int total_samples, short *samples) {
    short current_sample, next_sample, prev_sample;
    
    // Potential out-of-bounds read
    if (sample_index > 0) {
        prev_sample = samples[sample_index - 1];
    }
    
    current_sample = samples[sample_index];
    
    // Potential out-of-bounds read
    if (sample_index < total_samples - 1) {
        next_sample = samples[sample_index + 1];
    }
    
    // ... process current_sample with its neighboring samples
    
    // Potential out-of-bounds write
    samples[sample_index] = process_sample(prev_sample, current_sample, next_sample);
}

