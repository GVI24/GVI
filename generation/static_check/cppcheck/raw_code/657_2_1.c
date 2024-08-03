void decode_raw_audio(AudioBuffer *buffer, RawAudioStream *stream) {
    int samples_needed = buffer->samples_per_channel * buffer->num_channels;
    // Assuming stream->raw_data_size is valid for the number of samples_needed without checking
    for (int i = 0; i < samples_needed; i++) {
        buffer->audio_data[i] = stream->raw_data[i]; // Potential out-of-bounds read
    }
}

