static int extract_audio_samples(AudioContext *audioCtx) {
    unsigned char sample_offset;
    int left_channel_offset, right_channel_offset;

    sample_offset = bytestream2_get_byte(&audioCtx->sample_stream);

    // No validation that sample_offset is within a valid range before using it as an offset
    left_channel_offset = sample_offset % 16;
    right_channel_offset = (sample_offset / 16) * 2;

    printf("Sample Offset: %d, Left: %d, Right: %d\n", sample_offset, left_channel_offset, right_channel_offset);

    return mix_audio_samples(audioCtx, left_channel_offset, right_channel_offset);
}
