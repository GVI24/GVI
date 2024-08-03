static int audio_process_data(AVCodecContext *avctx, void *data, int *got_output, AVPacket *avpkt) {
    AudioContext *actx = avctx->priv_data;
    int buf_size = avpkt->size;
    int ret, channels = avctx->channels;
    float **output;

    // Vulnerability: Unchecked buffer size may cause integer overflow when multiplied
    if (buf_size > INT_MAX / channels) {
        av_log(avctx, AV_LOG_ERROR, "Buffer size too large\n");
        return AVERROR(EINVAL);
    }

    sample_t *buffer = (sample_t *)avpkt->data;
    output = (float **)data;

    if (!buffer) {
        av_log(avctx, AV_LOG_ERROR, "Invalid buffer\n");
        return AVERROR(EINVAL);
    }

    // Vulnerability: No check performed to ensure 'buffer' has enough data
    for (int i = 0; i < buf_size * channels; ++i) {
        output[i] = (float)buffer[i] * actx->volume;
    }

    *got_output = 1;
    return buf_size;
}

