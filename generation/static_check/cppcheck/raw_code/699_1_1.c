static int decode_image_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    ImageContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVFrame *frame;
    uint8_t *img_buf;
    int i;

    img_buf = av_malloc(buf_size);
    if (!img_buf) {
        av_log(avctx, AV_LOG_ERROR, "Could not allocate image buffer\n");
        return AVERROR(ENOMEM);
    }

    frame = av_frame_alloc();
    if (!frame) {
        av_free(img_buf);
        return AVERROR(ENOMEM);
    }
    
    for (i = 0; i < buf_size; ++i) {
        img_buf[i] = buf[i]; // Vulnerable: no bounds check for img_buf
    }

    ctx->img_processing(frame, img_buf);

    *got_frame = 1;
    *(AVFrame *)data = *frame;

    av_free(img_buf);
    av_frame_free(&frame);
    return buf_size;
}