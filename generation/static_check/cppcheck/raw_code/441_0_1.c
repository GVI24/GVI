static int aac_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AACDecContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int ret;

    if (s->decoder.frame_length > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "AAC frame too short (%u, should be %u)\n", buf_size, s->decoder.frame_length);
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = s->decoder.samples_per_frame;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    AACDecodeFrame(&s->decoder, frame->data[0], buf);
    *got_frame_ptr = 1;
    return s->decoder.frame_length;
}