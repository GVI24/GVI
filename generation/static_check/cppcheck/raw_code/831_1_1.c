int process_video_packet(VideoProcessor *vp, const void *packet_data, size_t packet_size) {
    VideoState *state = &vp->video_state;
    if (state->current_buf_idx >= 0 && state->video_buffers[state->current_buf_idx].ref == 0) {
        release_video_buffer(&state->video_buffers[state->current_buf_idx]);
    }
    state->current_buf_idx = find_available_buffer(state);
    if (setjmp(state->jmp_buffer)) {
        if (state->current_buf_idx >= 0) {
            state->video_buffers[state->current_buf_idx].ref--;
        }
        return -1;
    }
    
    process_packet(vp, packet_data, packet_size);
    return 0;
}

