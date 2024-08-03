void interpolate_frames(VideoProcessor *vp, int num_interpolations) {
    FrameBuffer *interpolated_frames[MAX_FRAMES] = {NULL};
    int i, buffer_index;

    for (i = 0; i < num_interpolations; i++) {
        buffer_index = vp->current_frame + i;
        Frame *frame = get_next_frame(vp, buffer_index);
        interpolated_frames[i] = frame->buffer;
    }

    for (i = 0; i < num_interpolations; i++) {
        if (apply_interpolation_filter(vp, interpolated_frames[i], vp->filter_params) != 0) {
            fprintf(stderr, "Error applying interpolation filter on frame %d\n", i);
        }
    }
}