static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AudioDecoderContext *ctx = avctx->priv_data;
    GetBitContext gb;

    if (buf_size < 128 * avctx->channels) {
        av_log(avctx, AV_LOG_ERROR, "Buffer is too small\n");
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = ctx->samples_per_frame;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    for (int ch = 0; ch < avctx->channels; ch++) {
        init_get_bits(&gb, &buf[128 * ch], 128 * 8);
        if (!decode_channel(ctx, &gb, frame->extended_data[ch])) {
            return AVERROR_INVALIDDATA;
        }
    }

    *got_frame_ptr = 1;
    return buf_size;
}