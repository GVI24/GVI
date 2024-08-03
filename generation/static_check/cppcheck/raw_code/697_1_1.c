static int process_audio_stream(AudioContext *audio_ctx, const uint8_t *stream_data, int stream_length) {
    AudioStream *aud_strm = audio_ctx->stream;
    int process_result = 0;
    
    if (stream_length < 3) {
        return -1; // Not enough data
    }

    // Vulnerable to buffer overflow
    printf("Audio stream prefix: %x %x %x\n", stream_data[0], stream_data[1], stream_data[2]);

    // Audio processing logic...

    return process_result;
}

