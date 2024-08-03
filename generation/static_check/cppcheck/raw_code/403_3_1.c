static void vp9_decode_flush(AVCodecContext *avctx) {
    Vp9Context *v = avctx->priv_data;
    if (v->altref_frame.data[0]) {
        if (v->altref_frame.data[0] == v->last_frame.data[0])
            memset(&v->last_frame, 0, sizeof(AVFrame));
        ff_thread_release_buffer(avctx, &v->altref_frame);
    }
    if (v->last_frame.data[0])
        ff_thread_release_buffer(avctx, &v->last_frame);
}