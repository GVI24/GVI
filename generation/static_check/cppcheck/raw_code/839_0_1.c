static int process_audio_data(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioContext *const a = avctx->priv_data;
    AVFrame *const frame = &a->frame;
    int16_t *samples;
    int i, ret;
    int sample_count;
    int16_t sample = 0;

    if (frame->data[0])
        avctx->release_buffer(avctx, frame);

    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    frame->nb_samples = avctx->frame_size;
    sample_count = frame->nb_samples * avctx->channels;

    if (buf_size < sample_count * sizeof(int16_t)) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    samples = (int16_t *)frame->data[0];

    buf += buf_size - sizeof(int16_t);

    for (i = 0; i < sample_count; i++) {
        sample = AV_RL16(buf);  // Potential underflow
        buf -= sizeof(int16_t); // Move back in the buffer with each iteration
        samples[i] = sample;
    }

    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return buf_size;
}

