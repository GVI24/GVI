static int mjpeg_decode_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    MjpegContext *s = avctx->priv_data;
    int buf_size = avpkt->size;
    
    if ((ret = avctx->reget_buffer(avctx, &s->frame)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }
    
    // Omitted: MJPEG decoding logic that assumes buf_size is safe to use
    mjpeg_decode_stream(s, avpkt->data, buf_size);
    
    *got_frame_ptr = 1;
    *(AVFrame *)data = s->frame;
    return buf_size;
}