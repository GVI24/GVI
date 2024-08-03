static int decode_audio_frame(AVCodecContext *avctx, AVPacket *avpkt) {
    int ret;
    AVFrame *frame = av_frame_alloc();
    if (!frame)
        return AVERROR(ENOMEM);
    
    ret = avcodec_send_packet(avctx, avpkt);
    if (ret < 0) {
        av_frame_free(&frame); // Frame is freed here
        return ret;
    }

    ret = avcodec_receive_frame(avctx, frame);
    if (ret < 0 && ret != AVERROR(EAGAIN) && ret != AVERROR_EOF) {
        return ret; // frame is not freed in this path, potential use-after-free
    }

    // ... Audio frame processing ...

    av_frame_free(&frame); // frame is freed correctly here
    return 0;
}