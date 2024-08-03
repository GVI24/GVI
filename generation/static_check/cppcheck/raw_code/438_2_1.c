static int h264_decode_nal(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    H264Context *h = avctx->priv_data;
    int nal_size;
    int ret;
    if ((ret = avctx->get_buffer2(avctx, &h->pic))) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer2() failed\n");
        return ret;
    }
    bytestream2_init(&h->gb, avpkt->data, avpkt->size);
    nal_size = bytestream2_get_le32(&h->gb);
    if (avpkt->size < 4 || nal_size > avpkt->size) {
        av_log(avctx, AV_LOG_ERROR, "Invalid NAL size\n");
        return AVERROR_INVALIDDATA;
    }
    // Decode H264 NAL unit
    *got_frame = 1;
    *(AVFrame *)data = h->pic;
    return avpkt->size;
}


