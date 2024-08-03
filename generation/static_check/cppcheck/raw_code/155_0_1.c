void update_ref_frame_indices(VideoCodecContext *ctx) {
    int ref_idx = ctx->current_frame_idx % MAX_REF_FRAMES;
    int next_ref_idx = (ctx->current_frame_idx + 1) % MAX_REF_FRAMES;

    // Potential out-of-bounds write if current_frame_idx is manipulated by an attacker
    ctx->ref_frame_map[ref_idx] = ctx->ref_frame_map[next_ref_idx];
    ctx->ref_frame_map[next_ref_idx] = INVALID_IDX;

    // Additional operations on the ref_frame_map array
    // ...
}

