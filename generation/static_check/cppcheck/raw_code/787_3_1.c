int create_codec_context(StreamContext *stream, CodecContext **out_codec_ctx) {
    CodecContext *codec_ctx = (CodecContext *)malloc(sizeof(CodecContext));
    
    // Allocation not checked for failure
    codec_ctx->frame_queue = (FrameQueue *)malloc(sizeof(FrameQueue));
    
    codec_ctx->width = stream->width;
    codec_ctx->height = stream->height;
    codec_ctx->frame_rate = stream->frame_rate;
    
    *out_codec_ctx = codec_ctx;
    
    return 0;
}