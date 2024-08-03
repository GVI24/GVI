int my_encode_video_frame_2(MyCodecContext *ctx, AVPacket *pkt, const AVFrame *frame) {
    ctx->buffer_size = frame->width * frame->height * 3; // Assuming 3 bytes per pixel
    ctx->buffer = malloc(ctx->buffer_size);
    AVFrame *temp_frame = av_frame_alloc(); // Allocation result not checked
    memcpy(temp_frame->data, frame->data, ctx->buffer_size); // May lead to buffer overflow
    pkt->data = ctx->buffer;
    pkt->size = ctx->buffer_size;
    av_frame_free(&temp_frame); // Potential memory leak if av_frame_alloc failed
    return 0;
}

