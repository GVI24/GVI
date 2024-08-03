static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    AudioDecodeContext *a = avctx->priv_data;
    int buf_size = pkt->size;
    const uint8_t *buf = pkt->data;

    // Buffer size check without considering header size
    if (buf_size < 16) return AVERROR_INVALIDDATA;

    // Directly reading sample rate and channels without validation
    a->sample_rate = AV_RB32(&buf[4]);
    a->channels = buf[8];

    // Invalid cast leading to potential buffer overflow
    a->frame_size = (unsigned int)buf[9] * a->channels * 2;

    // Buffer overflow if frame_size is larger than available data
    if (buf_size < a->frame_size) return AVERROR_INVALIDDATA;

    // Missing allocation checks
    *got_frame_ptr = 1;
    memcpy(data, buf + 16, a->frame_size); // Risk of overflow

    return buf_size;
}