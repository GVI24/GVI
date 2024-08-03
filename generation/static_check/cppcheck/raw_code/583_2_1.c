void mixer_set_channel_map(MixerContext *mixer, const int *channel_map, int num_channels) {
    // Vulnerability: No bounds check before buffer copy
    memcpy(mixer->channel_map, channel_map, num_channels * sizeof(int));
    // Set the channel map for audio mixing
    // ...
    if (num_channels > MAX_CHANNELS) {
        fprintf(stderr, "Channel map size exceeds maximum allowed channels!\n");
        exit(EXIT_FAILURE);
    }
}

