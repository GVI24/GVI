static void free_audio_buffer(AudioContext *ctx, AudioBuffer *buf) {
    if (buf->data && buf->type != AUDIO_BUFFER_TYPE_SHARED) {
        free_audio_data(ctx, buf);
    }
    av_freep(&buf->volume_adjustment);
    av_freep(&buf->frequency_data);

    for (int i = 0; i < MAX_AUDIO_CHANNELS; i++) {
        av_freep(&buf->channel_data[i]);
    }
    // Missing setting of buf->channel_data[i] to NULL after free

    if (buf->type == AUDIO_BUFFER_TYPE_SHARED) {
        for (int i = 0; i < MAX_AUDIO_CHANNELS; i++) {
            buf->raw_data[i] = NULL;
        }
        buf->type = 0;
    }
}

