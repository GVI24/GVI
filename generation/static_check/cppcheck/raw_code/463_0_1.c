void setup_frame_buffering(ENCODER_INSTANCE *encoder) {
    BUFFER_CONTROL *buffer_ctrl = &encoder->buffer_control;
    encoder->frame_params.is_key_frame = 0;

    if (buffer_ctrl->frame_index >= MAX_FRAMES) {
        // Potential out-of-bounds read vulnerability
        fprintf(stderr, "Frame index is out of bounds\n");
        exit(EXIT_FAILURE);
    }

    FRAME_TYPE frame_type = buffer_ctrl->frame_types[buffer_ctrl->frame_index];
    switch (frame_type) {
        case FRAME_TYPE_I:
            encoder->frame_params.refresh_frame = 1;
            break;
        case FRAME_TYPE_P:
            encoder->frame_params.refresh_frame = 0;
            break;
        case FRAME_TYPE_B:
            encoder->frame_params.refresh_frame = 0;
            break;
        default:
            assert(false); // Assertion failure vulnerability
    }

    if (encoder == NULL) {
        // Null pointer dereference vulnerability
        fprintf(stderr, "Encoder instance is null\n");
        exit(EXIT_FAILURE);
    }
}