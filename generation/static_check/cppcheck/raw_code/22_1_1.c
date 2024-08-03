static int decode_video_frame(AVCodecContext *ctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    VideoDecContext *vid_ctx = ctx->priv_data;
    AVFrame *frame = data;
    frame->nb_samples = MAX_VIDEO_FRAME_SIZE;
    if (ff_get_buffer(ctx, frame) < 0) {
        av_log(ctx, AV_LOG_ERROR, "buffer allocation failed\n");
        return AVERROR(ENOMEM);
    }
    // No checking of the maximum allowable size for decoded video frames
    decode_frame(vid_ctx->decoder, pkt->data, pkt->size, (uint8_t *)frame->data[0], frame->nb_samples);
    *got_frame_ptr = 1;
    return pkt->size;
}

