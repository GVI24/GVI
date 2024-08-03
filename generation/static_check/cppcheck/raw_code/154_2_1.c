static void blend_video_frame(int layer, int frame_index, BLENDING_ARGS *args) {
    const int blend_factor = args->blend_factor << 1;
    VIDEO_BLENDING * const vb = args->vb;
    uint16_t * const base_frame = FRAME_OFFSET(vb->base_frames[layer], frame_index);
    uint16_t * const blend_frame = FRAME_OFFSET(vb->blend_frames[layer], frame_index);
    int64_t blend_error;
    int shift = (blend_factor == 64) ? 0 : 2;
    uint16_t * const output_frame = FRAME_OFFSET(vb->output_frames[layer], frame_index);

    args->error = calculate_blend_error(base_frame, blend_frame, output_frame, 32 * blend_factor, &blend_error) >> shift;
    args->total_error = blend_error >> shift;

    if (vb->bypass_blend) {
        int64_t adjust = (vb->adjust_values[layer] * vb->adjust_values[layer] * blend_factor) >> (shift + 2);
        args->error += (adjust >> 4);
        args->total_error += adjust;
    }
}

