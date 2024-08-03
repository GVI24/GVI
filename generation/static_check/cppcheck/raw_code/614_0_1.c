static int audio_decode_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    AudioContext *ac = avctx->priv_data;
    AVFrame *frame = data;
    int ret;
    int buf_size;
    int chan_size = avpkt->size / avctx->channels;

    if (!ac->buffer) {
        ac->buffer = av_malloc(chan_size);
        if (!ac->buffer) {
            return AVERROR(ENOMEM);
        }
    }

    // Simplified processing for demonstration purposes
    if (chan_size > BUFFER_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "channel size exceeds buffer size\n");
        return AVERROR(EINVAL); // Memory is leaked here
    }

    memcpy(ac->buffer, avpkt->data, chan_size);

    // Process the buffer (omitted for brevity)

    frame->nb_samples = buf_size;
    if ((ret = ff_get_buffer(avctx, frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer failed\n");
        // Missing av_freep(&ac->buffer) here
        return ret;
    }

    // Assuming mono audio for simplicity
    raw_decode(frame->data[0], ac->buffer, buf_size);

    return avpkt->size;
}


