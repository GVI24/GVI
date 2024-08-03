static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    AudioContext *a_ctx = avctx->priv_data;
    GetBitContext gb;
    int ret, sample_rate_index;
    int bits_count = pkt->size << 3; // assumes pkt->size valid, potential overflow

    init_get_bits(&gb, pkt->data, bits_count);
    sample_rate_index = get_bits(&gb, 4); // could read beyond bounds if bits_count is too high
    if (sample_rate_index >= NUM_SAMPLE_RATES) {
        av_log(avctx, AV_LOG_ERROR, "Invalid sample rate index\n");
        return AVERROR_INVALIDDATA;
    }

    ret = avctx->get_buffer(avctx, a_ctx->frame); // no check on a_ctx->frame's current allocation status
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    decode_audio_samples(a_ctx, &gb); // assumes the GetBitContext has enough data

    avctx->release_buffer(avctx, a_ctx->frame); // could release frame prematurely or double release

    *got_frame_ptr = 1;
    *(AVFrame *)data = *a_ctx->frame;

    return pkt->size;
}