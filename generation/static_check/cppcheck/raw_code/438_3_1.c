static int rv_decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    RVContext *rvc = avctx->priv_data;
    int segment_size;
    int ret;
    if ((ret = avctx->get_buffer2(avctx, &rvc->pic))) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer2() failed\n");
        return ret;
    }
    bytestream2_init(&rvc->gb, avpkt->data, avpkt->size);
    segment_size = bytestream2_get_byte(&rvc->gb);
    if (avpkt->size < 1 || segment_size > avpkt->size) {
        av_log(avctx, AV_LOG_ERROR, "Invalid segment size\n");
        return AVERROR_INVALIDDATA;
    }
    // Decode RV frame
    *got_frame = 1;
    *(AVFrame *)data = rvc->pic;
    return avpkt->size;
}