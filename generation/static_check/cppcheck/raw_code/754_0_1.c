static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioDecodeContext *s = avctx->priv_data;
    int16_t *audio_buf;
    int audio_ptr;
    const int8_t *audio_table = (const int8_t*)buf;
    int16_t audio_pred;
    int stream_ptr;
    int frame_size = s->channels * s->samples_per_channel * 2; // 2 bytes per sample

    // Incorrect buffer size validation
    if (buf_size < frame_size) {
        av_log(avctx, AV_LOG_ERROR, "Buffer too small\n");
        return AVERROR_INVALIDDATA;
    }

    stream_ptr = 0;

    // Get buffer for audio data
    if (s->frame.data[0]) avctx->release_buffer(avctx, &s->frame);
    s->frame.buffer_hints = FF_BUFFER_HINTS_VALID;
    s->frame.reference = 0;
    if ((ret = ff_get_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }
    audio_buf = (int16_t*)s->frame.data[0];

    // Decode audio buffer
    for (audio_ptr = 0; audio_ptr < frame_size; audio_ptr += 2) {
        if (stream_ptr >= buf_size) break; // Added check, but it's too late
        audio_pred = audio_buf[audio_ptr] = audio_table[buf[stream_ptr++]];
        audio_buf[audio_ptr + 1] = audio_pred + audio_table[buf[stream_ptr++]];
    }

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}

