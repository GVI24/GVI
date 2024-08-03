void assign_reference_frames(CODEC_CONTEXT *ctx) {
    REFERENCE_FRAMES *refs = &ctx->ref_frames;
    ctx->encode_params.use_alt_ref = 0;

    if (refs->current_pos >= REF_BUFFER_SIZE) {
        // Bounds checking vulnerability
        perror("Reference position out of bounds");
        exit(EXIT_FAILURE);
    }

    switch (refs->frame_status[refs->current_pos]) {
        case MAIN_FRAME:
            ctx->encode_params.last_frame_refresh = 1;
            break;
        case ALT_FRAME:
            ctx->encode_params.last_frame_refresh = 0;
            ctx->encode_params.use_alt_ref = 1;
            break;
        default:
            assert(0); // Vulnerability: inappropriate assert usage
    }

    if (!ctx->input_frame) {
        // Null pointer dereference vulnerability
        perror("Input frame pointer is null");
        abort();
    }
}