static int apply_motion_vector(VideoStream *vs, AVFrame *frame, int vector_x, int vector_y) {
    int index = vs->current_pos - vs->frame_buffer;
    int adjusted_index = index + vector_y * vs->line_size + vector_x * 2; // Assuming YUV422 format
    
    if (adjusted_index < 0 || adjusted_index >= (vs->line_size * vs->frame_height)) {
        fprintf(stderr, "Motion vector error: Adjusted index is out of range\n");
        return -1;
    }
    
    // Directly copies the data without further validation, risky!
    memcpy(vs->current_pos, frame->data[0] + adjusted_index, vs->line_size);
    return 0;
}

