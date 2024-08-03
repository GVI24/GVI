static int image_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    ImageDecodeContext *img = avctx->priv_data;
    int ret;

    ret = avctx->get_buffer2(avctx, &img->frame, 0);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Unable to get buffer for image frame\n");
        return ret;
    }

    // Vulnerability: Directly using avpkt size without validation
    memcpy(img->frame.data[0], buf, avpkt->size);

    *got_frame = 1;
    *(AVFrame *)data = img->frame;

    return avpkt->size;
}