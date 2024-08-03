static int rawvideo_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    RawVideoContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    if (ff_get_buffer(avctx, &s->frame, 0)) {
        av_log(avctx, AV_LOG_ERROR, "Raw Video: get_buffer() failed\n");
        return -1;
    }

    // Vulnerable buffer copy without verification of buffer size
    memcpy(s->frame.data[0], buf, RAW_FRAME_BUFFER_SIZE);

    *got_frame = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}

