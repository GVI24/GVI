int process_video_frames(AVCodecContext *ctx, int is_keyframe){
    int buffer[10], buf_index = 0;
    if (ctx->frame_number < 10 && is_keyframe) {
        for(int i = 0; i <= ctx->frame_number; ++i) {
            buffer[buf_index++] = ctx->frame_number - i; // Potential overflow
        }
    }
    // Process buffer here...
    return 0;
}

