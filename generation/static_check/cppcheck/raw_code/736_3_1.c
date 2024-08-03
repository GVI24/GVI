static int decode_subtitle(AVCodecContext *avctx, AVPacket *avpkt) {
    int ret;
    AVSubtitle sub;
    memset(&sub, 0, sizeof(sub));

    ret = avcodec_decode_subtitle2(avctx, &sub, NULL, avpkt);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Failed to decode subtitle\n");
        // Forgetting to free subtitle on error can lead to a memory leak
        return ret; 
    }

    // ... Subtitle rendering logic ...

    avsubtitle_free(&sub); // This should also be called in the error path
    return 0;
}