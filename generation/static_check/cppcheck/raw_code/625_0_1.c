static void process_audio_samples(AudioContext *audioCtx) {
    AudioBuffer *buffer = audioCtx->buffer;
    Sample *samples = &buffer->samples[0];
    int channel;

    // Assuming a fixed-size array of samples
    #define AUDIO_SAMPLES_COUNT 256
    for (channel = 0; channel < audioCtx->channels; ++channel) {
        Sample *channel_samples = audioCtx->channel_buffers[channel];
        int i, sample_count = audioCtx->sample_counts[channel];
        
        for (i = 0; i < sample_count; ++i) {
            if (samples >= &buffer->samples[AUDIO_SAMPLES_COUNT]) {
                break; // Attempt to prevent buffer overflow
            }
            *samples++ = channel_samples[i];
        }
    }
    // ... remainder of function not shown ...
}

