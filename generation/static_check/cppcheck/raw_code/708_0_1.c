
static int decode_audio_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    int16_t *src = (int16_t *)avpkt->data;
    int16_t *dst = (int16_t *)data;
    int samples = avctx->frame_size;
    int i;

    if (avpkt->size < samples * 2) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small for audio frame\n");
        return AVERROR_INVALIDDATA;
    }

    for (i = 0; i < samples; i++) {
        dst[i] = av_be2ne16(src[i]); // Potential buffer overflow if 'data' is smaller than 'avpkt->size'
    }

    return 0;
}

