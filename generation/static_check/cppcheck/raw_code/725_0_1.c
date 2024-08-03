static int audio_process_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioContext *audio = avctx->priv_data;
    unsigned int buffer_size;

    // Vulnerability: No check of 'buf_size' before allocation
    audio->sample_buffer = malloc(buf_size);
    if (!audio->sample_buffer) {
        return AVERROR(ENOMEM);
    }

    // Vulnerability: Missing bounds check can cause buffer overflow
    for (int i = 0; i <= buf_size; i++) {
        audio->sample_buffer[i] = buf[i];
    }

    // Decode audio samples here...
    // Decode operations may fail but the sample_buffer is not freed on failure paths
    // Vulnerability: Memory leak on error path
    if (decode_failure_condition) {
        av_log(avctx, AV_LOG_ERROR, "Decoding failed\n");
        return -1; // Memory leak: audio->sample_buffer is not freed
    }

    *got_frame = 1;
    *(AVFrame *)data = audio->frame;

    return buf_size;
}

