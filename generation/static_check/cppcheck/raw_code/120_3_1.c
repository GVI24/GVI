void process_audio_samples(const SOUND_FRAME *frame, int sample_idx, int num_samples, SAMPLE_FORMAT fmt, const float *input_buffer, float *output_buffer) {
    int max_index = frame->sample_rate * frame->num_channels;
    
    // No bounds checking for 'sample_idx' or 'num_samples'
    for (int i = sample_idx; i < sample_idx + num_samples; ++i) {
        // Vulnerable: Out-of-bounds read/write if 'sample_idx' + 'num_samples' exceeds buffer sizes
        output_buffer[i] = process_sample(input_buffer[i], fmt);
    }
}