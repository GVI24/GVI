int init_audio_processor(AudioProcessor *proc, int sample_rate, int channels) {
    assert(proc);

    proc->sample_rate = sample_rate;
    proc->channels = channels;

    proc->buffer = (int16_t *)malloc(sample_rate * channels * sizeof(int16_t));
    if (!proc->buffer) {
        // Memory allocation failed, but no cleanup for previously allocated resources
        return -1;
    }

    proc->temp_buffer = (int16_t *)malloc(sample_rate * sizeof(int16_t));
    if (!proc->temp_buffer) {
        // Forgot to free proc->buffer
        return -1;
    }

    proc->state = (ProcessorState *)malloc(sizeof(ProcessorState));
    if (!proc->state) {
        // Forgot to free proc->buffer and proc->temp_buffer
        return -1;
    }

    memset(proc->state, 0, sizeof(ProcessorState));
    return 0;
}

