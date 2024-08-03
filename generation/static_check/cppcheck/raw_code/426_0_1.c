static int process_video_frame(AVCodecContext *avctx, AVFrame *frame) {
    VideoDecContext *vd = avctx->priv_data;
    VideoContext *vc = &vd->vc;
    int frame_ready = 0;

    if (vc->avctx->active_thread_type & FF_THREAD_FRAME)
        ff_thread_report_progress(&vc->next_frame_ptr->f, INT_MAX, 0);

    if (vc->frame_type == AV_PICTURE_TYPE_I || vc->low_delay) {
        *frame = vc->next_frame_ptr->f;  // Potential null pointer dereference
        frame_ready = 1;
    } else if (vc->prev_frame_ptr) {
        *frame = vc->prev_frame_ptr->f;
        frame_ready = 1;
    }

    if (frame_ready) update_video_stats(vc, frame);

    return frame_ready;
}
