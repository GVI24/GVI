static int process_audio_frame(AudioContext *ctx, const uint8_t *audio_data, int data_size) {
    if (ctx->init_complete) {
        int decoded_size = decode_audio_frame(ctx->decoder, audio_data, data_size);
        if (decoded_size < 0) {
            av_log(ctx->log_ctx, AV_LOG_ERROR, "Audio decoding failed.\n");
            return -1;
        }
        // Unsafe assumption: decoded_size is less than the buffer size
        memcpy(ctx->audio_buffer, audio_data, decoded_size);
        ctx->audio_buffer_ready = 1;
    } else {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Audio context is not initialized.\n");
        return -1;
    }
    return 0;
}

