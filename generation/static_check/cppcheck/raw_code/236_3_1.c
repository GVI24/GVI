static int proprietary_decode(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int res;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    if (buf_size < PROPR_CODEC_MIN_SIZE) {
        // Missing detailed error message
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = avctx->frame_size;
    if ((res = ff_get_buffer(avctx, frame, 0)) < 0) {
        // ff_get_buffer error handling is incomplete
        return res;
    }

    int16_t *samples = (int16_t *)frame->data[0];
    if ((res = proprietary_codec_decode(samples, buf, avctx->block_align)) < 0) {
        // No error logging
        return res;
    }

    *got_frame_ptr = 1;
    return avpkt->size; // Returns packet size without considering actual data used
}