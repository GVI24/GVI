static int decode_audio_frame(AVCodecContext *ctx, void *data, int *got_frame, AVPacket *pkt) {
    AudioContext *ac = ctx->priv_data;
    int sample_rate;
    int ret;
    if ((ret = ctx->get_buffer(ctx, &ac->frame))) {
        av_log(ctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }
    bytestream2_init(&ac->gb, pkt->data, pkt->size);
    sample_rate = bytestream2_get_le32(&ac->gb);
    if (pkt->size < 4 || sample_rate <= 0) {
        av_log(ctx, AV_LOG_ERROR, "Invalid packet size or sample rate\n");
        return AVERROR_INVALIDDATA;
    }
    // Decode audio frame
    *got_frame = 1;
    *(AVFrame *)data = ac->frame;
    return pkt->size;
}


