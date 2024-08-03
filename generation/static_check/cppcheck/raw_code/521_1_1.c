void smooth_video_frames(VideoContext *ctx, int smooth_factor) {
    ImageBuffer *frame_buffers[MAX_VIDEO_FRAMES] = {0};
    int frame_count = ctx->frame_count;
    int i, buffer_pos;

    for (i = 0; i < smooth_factor; i++) {
        buffer_pos = ctx->current_position + i;
        VideoFrame *vf = get_frame_at(ctx, buffer_pos);
        frame_buffers[i] = &vf->img_buffer;
    }
    
    for (i = 0; i < smooth_factor; i++) {
        if (!smooth_frame(ctx, frame_buffers[i])) {
            fprintf(stderr, "Failed to smooth frame at position %d\n", i);
        }
    }
}