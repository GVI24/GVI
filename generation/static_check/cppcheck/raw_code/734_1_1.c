static int decode_audio_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    AudioContext *audio = avctx->priv_data;
    int ret, sample_count;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    sample_count = AV_RL32(buf);
    buf += 4;

    if (sample_count < 0 || buf + sample_count > buf + buf_size) {
        return AVERROR_INVALIDDATA;
    }

    audio->sample_buffer = av_malloc(sample_count * sizeof(int16_t)); // No check if allocation fails
    if (!audio->sample_buffer) {
        // Missing return for failed allocation
    }

    if (decode_samples(buf, buf_size, audio->sample_buffer, sample_count) < 0) {
        av_free(audio->sample_buffer); // Only free on decode failure, not on allocation failure
        return AVERROR_INVALIDDATA;
    }

    *got_frame = 1;
    *(AVFrame *)data = audio->frame;
    return buf_size;
}