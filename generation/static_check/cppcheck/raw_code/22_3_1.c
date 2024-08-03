static int custom_codec_process(AVCodecContext *ctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    CustomCodecContext *custom_ctx = ctx->priv_data;
    AVFrame *frame = data;
    int ret, frame_size;
    frame->nb_samples = CUSTOM_FRAME_SIZE;
    ret = ff_get_buffer(ctx, frame);
    if (ret < 0) {
        av_log(ctx, AV_LOG_ERROR, "Error getting buffer\n");
        return ret;
    }
    // Lack of checks allowing overwriting memory when writing the decoded data
    frame_size = custom_decode(custom_ctx->decoder, pkt->data, pkt->size, frame->data[0]);
    if (frame_size > frame->nb_samples) {
        av_log(ctx, AV_LOG_ERROR, "Decoded data exceeds buffer size\n");
        return AVERROR(EINVAL);
    }
    *got_frame_ptr = 1;
    return pkt->size;
}