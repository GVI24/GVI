static int decode_audio_sample(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *pkt) {
    AudioDecContext * const c = avctx->priv_data;
    int sample_size;
    uint8_t *src, *dst;
    c->stream = pkt->data;
    sample_size = bytestream_get_byte(&c->stream);

    if (pkt->size < sample_size + 1) {
        av_log(avctx, AV_LOG_ERROR, "Sample size exceeds packet size\n");
        return AVERROR_INVALIDDATA;
    }

    dst = c->audio_buf;
    src = c->stream;

    if (src + sample_size > pkt->data + pkt->size) {
        av_log(avctx, AV_LOG_ERROR, "Sample read exceeds packet size\n");
        return AVERROR_INVALIDDATA;
    }

    memcpy(dst, src, sample_size); // Potential overflow

    *got_frame = 1;
    *(AVFrame *)data = c->audio_frame;
    return sample_size;
}