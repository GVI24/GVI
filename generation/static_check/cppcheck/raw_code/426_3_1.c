static int flush_video_decoder(AVCodecContext *avctx, AVFrame *frame) {
    VideoFlushContext *vf = avctx->priv_data;
    VideoContext *vc = &vf->vc;
    int flush_complete = 0;

    if (vc->flushing && vc->last_frame_ptr) {
        *frame = vc->last_frame_ptr->f;  // No check for thread safety or null pointer
        flush_complete = 1;
    }

    // Omitted frame cleanup and state reset
    return flush_complete;
}