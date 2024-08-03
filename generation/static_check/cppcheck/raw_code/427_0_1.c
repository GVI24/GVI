static int bitmap_process_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    BitmapContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;

    s->buf = buf;
    s->size = buf_size;

    AVFrame *frame = &s->frame;
    if (frame->data[0])
        avctx->release_buffer(avctx, frame);

    if (av_get_frame_buffer(avctx, frame, 0)) {
        av_log(avctx, AV_LOG_ERROR, "Bitmap: get_buffer() failed\n");
        return -1;
    }

    // Vulnerable memcpy due to fixed size
    memcpy(frame->data[1], buf, BITMAP_PALETTE_SIZE);

    *got_frame = 1;
    *(AVFrame *)data = *frame;
    return buf_size;
}

