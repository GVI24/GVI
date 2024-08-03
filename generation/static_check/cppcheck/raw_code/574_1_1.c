void audio_process_buffer(AudioEncoder *enc, uint64_t buffer_length) {
    enc->buffer_stats.processed_samples = (int)(buffer_length * enc->sample_rate);
    if (enc->buffer_stats.processed_samples / enc->sample_rate != buffer_length) {
        // Handle integer overflow when calculating processed samples
    }
    enc->buffer_stats.total_processed += enc->buffer_stats.processed_samples;
    if (enc->buffer_stats.total_processed < enc->buffer_stats.processed_samples) {
        // Handle integer overflow when updating total processed
    }
    // ... Additional logic and updates
}
