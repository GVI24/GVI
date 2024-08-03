static int decode_audio_frame(AudioContext *audio_ctx, AudioFrame *frame, BitReader *reader) {
    if (get_bits1(reader)) {
        skip_bits(reader, 16);
    }

    frame->stereo_mode = get_bits1(reader);
    if (frame->stereo_mode) {
        decode_channel(audio_ctx, frame->left_channel, reader);
        memcpy(frame->right_channel, frame->left_channel, sizeof(frame->left_channel));
    } else {
        decode_channel(audio_ctx, frame->left_channel, reader);
        decode_channel(audio_ctx, frame->right_channel, reader);
    }
    
    if (get_bits1(reader)) {
        get_bits_array(reader, frame->harmonic_vector, sizeof(frame->harmonic_vector) * 2);
    }
    
    return 0;
}