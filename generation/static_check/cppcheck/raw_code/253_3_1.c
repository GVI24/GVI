static void decompress_audio(SoundContext *snd_ctx, int16_t (*samples)[64], int channel, int position) {
    int channel_stride = snd_ctx->sound.channel_stride;
    uint8_t *channel_buf = snd_ctx->sound.data[channel] + position * channel_stride;

    // Potential buffer overflow if position is too large
    for (int k = 0; k < 64; k += 8) {
        memcpy(channel_buf + k, samples[k / 8], 8);
    }
}