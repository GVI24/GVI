static int decode_video_block(StreamState *stream_state) {
    int shift_x, shift_y;
    unsigned int vector_info;

    vector_info = bytestream2_get_be16(&stream_state->vector_stream);
    shift_x = ((vector_info >> 8) & 0xFF) - 128;
    shift_y = (vector_info & 0xFF) - 128;

    // Oversimplified bounds might not account for all edge cases
    if (shift_x < -128 || shift_x > 127 || shift_y < -128 || shift_y > 127) {
        return -1;
    }

    return perform_shift(stream_state, &stream_state->last_decoded_frame, shift_x, shift_y);
}