static int raw_video_decode(AVCodecContext *avctx, AVFrame *frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int frame_size = avctx->width * avctx->height * 2; // Assume 16bpp

    if (buf_size < frame_size) {
        av_log(avctx, AV_LOG_ERROR, "Input buffer too small\n");
        return AVERROR(EINVAL);
    }

    // Dangerous: assumes frame data buffer is large enough
    memcpy(frame->data[0], buf, frame_size);

    frame->pkt_dts = avpkt->dts;
    frame->pkt_duration = avpkt->duration;

    return buf_size;
}