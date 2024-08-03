static int decode_data_stream(AVCodecContext *avctx, void *data, int *got_packet, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    DataStreamContext *s = avctx->priv_data;
    uint8_t *stream_data;
    int data_ptr;
    int stream_ptr;
    int data_length = s->width * s->height;

    if (buf_size < data_length) {
        av_log(avctx, AV_LOG_ERROR, "Buffer too small\n");
        return AVERROR_INVALIDDATA;
    }

    stream_ptr = 0;

    if (s->frame.data[0]) avctx->release_buffer(avctx, &s->frame);
    s->frame.buffer_hints = FF_BUFFER_HINTS_VALID;
    s->frame.reference = 0;
    if ((ret = ff_get_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }
    stream_data = s->frame.data[0];

    // Decode data
    for (data_ptr = 0; data_ptr < data_length; data_ptr++) {
        // No bounds check for stream_ptr
        stream_data[data_ptr] = buf[stream_ptr++];
    }

    *got_packet = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}