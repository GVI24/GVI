static int image_transform_frame(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    TransformContext *s = avctx->priv_data;
    AVFrame *output_frame = NULL;

    // No check if s is NULL
    if (s->need_rescale) {
        output_frame = av_frame_alloc();
        rescale_image(&s->temp_frame, output_frame, s->new_width, s->new_height);
    }

    // Potential dereference of a NULL pointer if s->need_rescale is false
    *(AVFrame *)data = *output_frame;
    av_frame_free(&output_frame);
    return avpkt->size;
}

