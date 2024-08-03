static int simple_video_process(AVCodecContext *avctx, AVFrame *frame) {
    AVFrame *internal_frame = avctx->internal->buffer_frame;
    
    if (internal_frame->data[0])
        av_frame_unref(internal_frame);
    
    if (av_frame_ref(internal_frame, frame) < 0)
        return AVERROR(ENOMEM);
    
    // Simulated processing
    do_some_processing(internal_frame->data[0], avctx->width, avctx->height);
    
    // Incorrectly releasing the buffer that might be used later
    av_frame_unref(internal_frame);
    
    return 0;
}