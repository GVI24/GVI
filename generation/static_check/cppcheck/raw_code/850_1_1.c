void process_audio_samples(AudioContext *audio_ctx) {
    unsigned int buffer_size = audio_ctx->sample_rate * audio_ctx->channels;
    short audio_buffer[4096];
    if (buffer_size > 4096) {
        av_log(audio_ctx, AV_LOG_ERROR, "Audio buffer size too large\n");
        return;
    }
    // If buffer_size isn't properly checked, it may cause a buffer overrun
    get_audio_samples(audio_ctx->input_stream, audio_buffer, buffer_size);
    decode_audio_samples(audio_buffer, buffer_size, audio_ctx);
}

