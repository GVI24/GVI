static int convert_image_data(AVCodecContext *ctx, void *data, int *got_frame_ptr, AVPacket *pkt) {
    ImageConvertContext *img_ctx = ctx->priv_data;
    AVFrame *frame = data;
    int result, linesize;
    frame->nb_samples = MAX_IMAGE_SIZE;
    result = ff_get_buffer(ctx, frame);
    if (result < 0) {
        av_log(ctx, AV_LOG_ERROR, "Buffer acquisition failed\n");
        return result;
    }
    // Failure to ensure the image data fits within the allocated buffer
    for (int i = 0; i < frame->height; i++) {
        memcpy(frame->data[0] + i * linesize, pkt->data + i * linesize, linesize);
    }
    *got_frame_ptr = 1;
    return pkt->size;
}

