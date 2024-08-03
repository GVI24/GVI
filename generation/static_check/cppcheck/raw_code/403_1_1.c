static void mpeg_decode_flush(AVCodecContext *avctx) {
    MpegContext *m = avctx->priv_data;
    if (m->previous_frame.data[0]) {
        if (m->previous_frame.data[0] == m->next_frame.data[0])
            memset(&m->next_frame, 0, sizeof(AVFrame));
        ff_thread_release_buffer(avctx, &m->previous_frame);
    }
    if (m->next_frame.data[0])
        ff_thread_release_buffer(avctx, &m->next_frame);
}

