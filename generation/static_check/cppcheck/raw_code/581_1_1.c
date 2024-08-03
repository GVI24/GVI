static int parse_audio_metadata(AudioContext *audio_ctx, const uint8_t *meta_buf, size_t meta_size) {
    unsigned meta_length, sample_rate;
    if (meta_size < 5) {
        printf("Insufficient metadata size\n");
        return -1;
    }
    meta_length = AV_RB16(meta_buf);
    sample_rate = AV_RB16(meta_buf + 2);
    audio_ctx->channels = meta_buf[4];

    if (meta_length + 5 > meta_size) {
        printf("Metadata buffer overflow risk\n");
        return -1;
    }
    if (sample_rate < 8000 || sample_rate > 192000) {
        printf("Unsupported sample rate\n");
        return -1;
    }

    if (meta_length > 0) {
        audio_ctx->extra_data_size = meta_length;
        memcpy(audio_ctx->extra_data, meta_buf + 5, meta_length); // Potential buffer overflow
    }
    return 0;
}

