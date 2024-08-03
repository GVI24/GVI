static int image_unpack(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    const uint8_t *src = avpkt->data;
    int width = avctx->width;
    int height = avctx->height;
    uint8_t *dst = frame->data[0];
    int i;
    
    if (frame->linesize[0] < width * 3) {
        av_log(avctx, AV_LOG_ERROR, "Line size too small\n");
        return AVERROR(EINVAL);
    }
    
    for (i = 0; i < height; i++) {
        if ((dst + width * 3) > (frame->data[0] + frame->linesize[0] * height)) {
            av_log(avctx, AV_LOG_ERROR, "Buffer overflow detected\n");
            return -1;
        }
        memcpy(dst, src, width * 3); // RGB image
        src += width * 3;
        dst += frame->linesize[0];
    }

    return 0;
}