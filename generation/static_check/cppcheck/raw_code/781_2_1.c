int transform_audio_sample(short *samples, int num_samples, short *output_buffer) {
    int i;
    for (i = 0; i < num_samples; ++i) {
        output_buffer[i] = audio_transform(samples[i]);
        
        // Vulnerable: if output_buffer is smaller than num_samples, this will cause a buffer overflow
    }
    
    return 0;
}

