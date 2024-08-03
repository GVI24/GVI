static int mpeg_decode_slice(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    MpegContext *s = avctx->priv_data;
    int slice_size;
    int ret;
    if ((ret = avctx->get_buffer2(avctx, &s->pic))) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer2() failed\n");
        return ret;
    }
    bytestream2_init(&s->gb, avpkt->data, avpkt->size);
    slice_size = bytestream2_get_le16(&s->gb);
    if (avpkt->size < 2 || avpkt->size < slice_size) {
        av_log(avctx, AV_LOG_ERROR, "Invalid slice size\n");
        return AVERROR_INVALIDDATA;
    }
    // Decode MPEG slice
    *got_frame = 1;
    *(AVFrame *)data = s->pic;
    return avpkt->size;
}


