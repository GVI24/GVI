static void h264_decode_flush(AVCodecContext *avctx) {
    H264Context *h = avctx->priv_data;
    if (h->reference_frames[0].data[0]) {
        if (h->reference_frames[0].data[0] == h->current_frame.data[0])
            memset(&h->current_frame, 0, sizeof(AVFrame));
        ff_thread_release_buffer(avctx, &h->reference_frames[0]);
    }
    if (h->current_frame.data[0])
        ff_thread_release_buffer(avctx, &h->current_frame);
}

