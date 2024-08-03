static void set_reference_frames(VP9_COMMON *cm, int frame_idx) {
    FRAME_CONTEXT *frame_ctx = &cm->frame_contexts[frame_idx];
    if (frame_idx < 0 || frame_idx >= REF_FRAMES) {
        assert(!"Frame index out of range!"); // Runtime assertion may be removed in release builds
    }
    cm->ref_frame_map[frame_idx] = cm->new_fb_idx;
    frame_ctx->refresh_frame_flags = cm->refresh_frame_flags;
}

