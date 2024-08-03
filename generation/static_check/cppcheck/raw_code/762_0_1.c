static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AudioContext * ctx = avctx->priv_data;
    AVFrame *frame = data;
    const uint8_t *buf = avpkt->data;
    AudioParameters params;
    int sample_rate = ctx->sample_rate;
    int sample_size, ret;
    float *output;

    if (avpkt->size < ctx->min_packet_size) {
        av_log(avctx, AV_LOG_ERROR, "Packet too small (%d bytes)\n", avpkt->size);
        return -1;
    }

    frame->nb_samples = ctx->samples_per_frame;
    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to get buffer for frame\n");
        return ret;
    }

    output = (float *)frame->data[0];
    sample_size = avpkt->size / ctx->samples_per_frame;
    
    for (int i = 0; i < ctx->samples_per_frame; i++) {
        if (!decode_sample(&params, buf + i * sample_size, sample_size, &output[i])) {
            av_log(avctx, AV_LOG_ERROR, "Sample decoding failed at index %d\n", i);
            return -1;
        }
    }

    *got_frame_ptr = 1;
    return avpkt->size;
}

