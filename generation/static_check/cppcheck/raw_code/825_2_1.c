void clear_audio_buffer(AudioBufferContext *abc) {
    // Potential buffer overflow if abc->samples buffer is smaller than expected
    memset(abc->samples, 0, abc->num_channels * abc->samples_per_channel * sizeof(float));
}

