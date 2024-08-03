void update_frame_stats(EncoderState *state) {
    int frame_size = state->current_frame_size;
    state->total_encoded_frames += 1;
    state->total_bits_used += frame_size;
    if (frame_size > state->max_frame_size) {
        state->max_frame_size = frame_size;
    }
    
    // Potential overflow if total_bits_used or frame_size is very large
    state->average_bitrate = (state->total_bits_used / state->total_encoded_frames);
}

