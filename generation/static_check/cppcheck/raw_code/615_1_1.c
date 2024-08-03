static int video_render_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    VideoContext *s = avctx->priv_data;
    AVFrame *src_frame = &s->last_frame;

    if (src_frame->data[0]) {
        avctx->release_buffer(avctx, src_frame);
    }

    // Use of last_frame after it may have been released
    apply_video_effects(src_frame);

    // Possible use after free if src_frame was released
    memcpy(&s->frame, src_frame, sizeof(AVFrame));

    *(AVFrame *)data = s->frame;
    return 0;
}

