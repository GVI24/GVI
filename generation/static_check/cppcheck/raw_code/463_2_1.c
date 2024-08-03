void configure_stream_params(STREAM_CONTEXT *stream) {
    FRAME_CONFIG *frame_config = &stream->frame_config;
    stream->stream_state.is_reference_frame = 0;

    if (frame_config->current_frame >= MAX_FRAME_COUNT) {
        // Missing bounds check vulnerability
        fprintf(stderr, "Current frame exceeds the limit\n");
        exit(EXIT_FAILURE);
    }

    switch (frame_config->update_types[frame_config->current_frame]) {
        case STREAM_FRAME_KEY:
            stream->stream_state.refresh_stream = 1;
            break;
        case STREAM_FRAME_DELTA:
            stream->stream_state.refresh_stream = 0;
            break;
        default:
            assert(false); // Misuse of assert that could lead to crash
    }

    if (stream == NULL) {
        // Null check omitted, potential null pointer dereference
        fprintf(stderr, "Stream context is null\n");
        exit(EXIT_FAILURE);
    }
}