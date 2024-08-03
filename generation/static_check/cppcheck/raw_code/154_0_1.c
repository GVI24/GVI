static void process_audio_frame(int channel, int frame, int frame_size, struct audio_process_args *args) {
    const int enhanced_frame_size = frame_size * 2;
    AUDIO_PROCESSING * const ap = args->ap;
    int32_t * const audio_buf = FRAME_OFFSET(ap->audio_buffer, frame);
    int64_t temp;
    int shift = (frame_size > 256) ? 1 : 3;
    int32_t * const processed = FRAME_OFFSET(ap->processed_buffer, frame);

    args->error = calculate_audio_error(audio_buf, processed, 8 * enhanced_frame_size, &temp) >> shift;
    args->total_error = temp >> shift;

    if (ap->skip_processing) {
        int64_t adjust = (ap->adjustment_factor * ap->adjustment_factor * enhanced_frame_size) >> (shift + 2);
        args->error += (adjust >> 4);
        args->total_error += adjust;
    }
}

