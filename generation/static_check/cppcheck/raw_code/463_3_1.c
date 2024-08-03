void update_codec_state(VIDEO_CODEC *codec) {
    STATE_MANAGER *state_mgr = &codec->state_manager;
    codec->codec_params.frame_is_intra = 0;

    if (state_mgr->frame_counter > MAX_FRAME_LIMIT) {
        // Buffer overflow vulnerability due to lack of bounds check
        perror("Frame counter exceeded maximum limit");
        exit(EXIT_FAILURE);
    }

    FRAME_UPDATE_TYPE update_type = state_mgr->update_schedule[state_mgr->frame_counter];
    switch (update_type) {
        case UPDATE_INTRA:
            codec->codec_params.refresh_intra_frame = 1;
            break;
        case UPDATE_INTER:
            codec->codec_params.refresh_intra_frame = 0;
            break;
        case UPDATE_NONE:
            // Missing case, should handle the UPDATE_NONE case
            break;
        default:
            assert(0); // Assertion misuse can lead to a crash
    }

    if (codec->raw_input == NULL) {
        // Vulnerability: dereferencing a potential null pointer
        perror("Raw input frame data is null");
        abort();
    }
}