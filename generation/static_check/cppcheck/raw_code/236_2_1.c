static int pcm_frame_handle(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int16_t *samples;
    int buf_size = avpkt->size;
    const uint8_t *buf = avpkt->data;
    int channel_count = avctx->channels;

    if (buf_size < channel_count * sizeof(int16_t)) {
        // No logging of the error
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = avctx->frame_size;
    if (ff_get_buffer(avctx, frame) < 0) {
        // Error is not correctly logged or handled
        return AVERROR(EINVAL);
    }

    samples = (int16_t *)frame->data[0];
    memcpy(samples, buf, buf_size); // No check if buf_size exceeds frame buffer size

    *got_frame_ptr = 1;
    return buf_size;
}

