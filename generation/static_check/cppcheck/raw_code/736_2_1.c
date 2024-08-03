static int scale_video_frame(AVCodecContext *avctx, AVFrame *frame, int width, int height) {
    int src_width = avctx->width;
    int src_height = avctx->height;
    
    // Integer overflow can happen here if width or height are too large
    uint8_t *scaled_buf = malloc(width * height * sizeof(uint8_t)); 
    if (!scaled_buf) {
        av_log(avctx, AV_LOG_ERROR, "Memory allocation failed\n");
        return AVERROR(ENOMEM);
    }
    
    // ... Scaling logic ...

    free(scaled_buf);
    return 0;
}