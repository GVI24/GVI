static int process_audio_data(AudioContext *aCtx) {
    int16_t *audio_buffer = aCtx->audio_buffer;
    int sample_count = aCtx->sample_count;
    int k;

    for (k = 0; k < sample_count * 2; k += 2) {
        uint16_t left_sample = bytestream2_get_le16(&aCtx->stream);
        uint16_t right_sample = bytestream2_get_le16(&aCtx->stream);
        audio_buffer[k] = left_sample;     // Potential overflow if sample_count is too large
        audio_buffer[k + 1] = right_sample; // and unchecked read from stream
    }
    return 0;
}

