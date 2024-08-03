static int transform_audio_frame(AVCodecContext *avctx, AVFrame *frame, const uint8_t *input) {
    TransformContext *tctx = avctx->priv_data;
    int sample_count = frame->nb_samples;
    int total_size = sample_count * avctx->channels;
    
    if (total_size > MAX_FRAME_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "Frame size exceeds maximum allowed size.\n");
        return AVERROR(EINVAL); // Potential buffer overflow
    }

    tctx->transform_buffer = av_malloc(total_size);
    if (!tctx->transform_buffer) {
        return AVERROR(ENOMEM);
    }

    // Unsafe copy, no verification that input has enough data
    memcpy(tctx->transform_buffer, input, total_size);

    // Transformation code omitted

    memcpy(frame->data[0], tctx->transform_buffer, total_size);

    // Memory should be freed later, but if transform logic has an issue or early return, it will leak
    return 0;
}