void process_audio_data(AudioBuffer *buffer, RawAudioStream *stream) {
    for (int i = 0; i < buffer->num_channels; i++) {
        // Potential buffer overflow if stream->raw_data_size > buffer->samples_per_channel
        memcpy(buffer->audio_data + i * buffer->samples_per_channel, stream->raw_data, stream->raw_data_size);
    }
}

