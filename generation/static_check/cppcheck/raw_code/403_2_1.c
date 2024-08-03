static void hevc_decode_flush(AVCodecContext *avctx) {
    HevcContext *h = avctx->priv_data;
    if (h->temporal_frame.data[0]) {
        if (h->temporal_frame.data[0] == h->working_frame.data[0])
            memset(&h->working_frame, 0, sizeof(AVFrame));
        ff_thread_release_buffer(avctx, &h->temporal_frame);
    }
    if (h->working_frame.data[0])
        ff_thread_release_buffer(avctx, &h->working_frame);
}

