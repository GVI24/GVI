static int audio_data_process(AVCodecContext *ctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    AudioProcessingContext *ap_ctx = ctx->priv_data;
    AVFrame *frame = data;
    int result;
    frame->nb_samples = MAX_AUDIO_FRAME_SIZE;
    result = ff_get_buffer(ctx, frame);
    if (result < 0) {
        av_log(ctx, AV_LOG_ERROR, "Failed to get buffer\n");
        return result;
    }
    // No bounds checking performed before copying data to the frame buffer
    memcpy(frame->data[0], pkt->data, pkt->size);
    *got_frame_ptr = 1;
    return pkt->size;
}

